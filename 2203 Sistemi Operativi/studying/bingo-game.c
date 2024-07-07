#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

#include "lib-misc.h"

#define RANDOM_NUMBER_RANGE_START 1
#define RANDOM_NUMBER_RANGE_END 75

#define DECK_SIZE (RANDOM_NUMBER_RANGE_END - RANDOM_NUMBER_RANGE_START + 1)

typedef enum e_game_state {
	WAITING_EXTRACTION,
	WAITING_CHECK
} game_state;

typedef enum e_check_state {
	NONE, // no win
	CINQUINA,
	BINGO
} check_state;

typedef struct s_shared_data {
	int last_extracted_number;
	game_state state;
	bool is_cinquina_available;
	pthread_mutex_t mutex;
	pthread_cond_t cond_wait_extraction;
	pthread_cond_t cond_wait_check;
	pthread_barrier_t barrier_check_done;
} shared_data;

typedef struct s_player_data {
	int card[3][5];
	int id;
	pthread_t tid;
	check_state state;
	shared_data *shared_ptr;
} player_data;

void print_card(int card[3][5]) {
	for (int i = 0; i < 3; i++) {
		printf("(");
		for (int j = 0; j < 5; j++) {
			printf("%d", card[i][j]);
			if (j != 4)
				printf(",");
		}
		printf(")");
		if (i != 2)
			printf(" / ");
	}
	printf("\n");
}

void fill_card(int card[3][5]) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++)
			card[i][j] = (rand() % (RANDOM_NUMBER_RANGE_START - RANDOM_NUMBER_RANGE_END + 1)) + RANDOM_NUMBER_RANGE_START;
}

void random_fill_numbers(int *deck) {
	for (int i = 0; i < DECK_SIZE; i++)
		deck[i] = RANDOM_NUMBER_RANGE_START + i;
	
	// shuffle
	for (int i = 0; i < DECK_SIZE; i++) {
		int x = rand() % DECK_SIZE;
		int y = rand() % DECK_SIZE;
		
		int tmp = deck[x];
		deck[x] = deck[y];
		deck[y] = tmp;
	} 
}

int extract_random_number(int *deck, int *deck_size_ptr) {
	
	if (*deck_size_ptr == 0)
		return -1;
	
	return deck[--(*deck_size_ptr)];	
}

void* player_thread(void* args) {
	player_data *data = args;
	
	flockfile(stdout);
	printf("P%d: ricevuta card ", data->id);
	print_card(data->card);
	funlockfile(stdout);
		
	while (true) {
	
		pthread_mutex_lock(&data->shared_ptr->mutex);
		
		while (data->shared_ptr->state != WAITING_EXTRACTION)
			pthread_cond_wait(&data->shared_ptr->cond_wait_extraction, &data->shared_ptr->mutex);
		
		printf("P%d: controllo se ho il numero %d...\n", data->id, data->shared_ptr->last_extracted_number);	
		pthread_mutex_unlock(&data->shared_ptr->mutex);
		
		int ret = pthread_barrier_wait(&data->shared_ptr->barrier_check_done);

		if (ret == PTHREAD_BARRIER_SERIAL_THREAD) {
			pthread_mutex_lock(&data->shared_ptr->mutex);
			
			data->shared_ptr->state = WAITING_CHECK;
			pthread_cond_signal(&data->shared_ptr->cond_wait_check);
			
			pthread_mutex_unlock(&data->shared_ptr->mutex);
		}
	
	}
	
	return NULL;
}

int main(int argc, char** argv) {

	if (argc != 3) {
		exit_with_err_msg("Usage: %s <n> <m>", argv[0]);
	}
	
	srand(time(NULL));

	long n = atoi(argv[1]);
	long m = atoi(argv[2]);
	
	shared_data shared;
	shared.state = WAITING_EXTRACTION;
	
	if (pthread_mutex_init(&shared.mutex, NULL))
		exit_with_err_msg("pthread_mutex_init");
	if (pthread_cond_init(&shared.cond_wait_extraction, NULL))
		exit_with_err_msg("pthread_cond_init");
	if (pthread_cond_init(&shared.cond_wait_check, NULL))
		exit_with_err_msg("pthread_cond_init");
	if (pthread_barrier_init(&shared.barrier_check_done, NULL, n) != 0)
		exit_with_err_msg("pthread_barrier_init");
	
	printf("D: ci saranno %d giocatori con %d card ciascuno\n", n, m);

	player_data players[n];

	for (int i = 0; i < n; i++) {
		players[i].id = i+1;
		players[i].shared_ptr = &shared;
		
		printf("D: genero e distribuisco la card n.%d: ", i+1);
		fill_card(players[i].card);
		print_card(players[i].card);

		pthread_create(&players[i].tid, NULL, player_thread, players+i);
	}
	
	printf("D: fine della distribuzione delle card e inizio di estrazione dei numeri\n");
	
	int deck[DECK_SIZE], deck_size = DECK_SIZE;
	random_fill_numbers(deck);
	
	
	bool isPlaying = true;
	while (isPlaying) {
		int random_number = extract_random_number(deck, &deck_size);
		if (random_number == -1) {
			exit_with_err_msg("BUG: sono stati estratti tutti i numeri e non c'è nessun vincitore\n");
		}
		
		pthread_mutex_lock(&shared.mutex);
		
		pthread_cond_broadcast(&shared.cond_wait_extraction);
		
		shared.last_extracted_number = random_number;
		shared.state = WAITING_EXTRACTION;
		while (shared.state != WAITING_CHECK)
			pthread_cond_wait(&shared.cond_wait_check, &shared.mutex);
		
		pthread_mutex_unlock(&shared.mutex);
		
		printf("D: estrazione del prossimo numero: %d\n", random_number);
	}
	
	return 0;
}

