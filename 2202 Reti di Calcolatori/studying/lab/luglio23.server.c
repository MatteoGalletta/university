#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdbool.h>

#define NUMBER_OF_PLAYERS 2

#define TO_GUESS_WORDS_COUNT 4
char* TO_GUESS_WORDS[TO_GUESS_WORDS_COUNT] = { "PALLONE", "VALIGIA", "KEK", "KHOK" };

typedef struct s_user {
  struct sockaddr_in addr;
  int lives;
  char* name;
} user;

int main(int argc, char **argv){

    int sockfd, n;
    struct sockaddr_in local_addr;
	socklen_t len = sizeof(struct sockaddr_in);
    char msg[1000];

    if(argc < 2){
        printf("Errore! Inserisci numero Port\n");
        return -1;
    }

    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        printf("Errore nell'apertura di socket!\n");
        return -1;
    }

    memset(&local_addr, 0, len);
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(atoi(argv[1]));

    if(bind(sockfd, (struct sockaddr *)&local_addr, len) < 0){
        printf("Errore nell'apertura di bind\n");
        return -1;
    }

    user users[NUMBER_OF_PLAYERS];
    int connectedPlayers = 0;
	while (connectedPlayers < NUMBER_OF_PLAYERS) {
    	struct sockaddr_in current_remote_addr;
        n = recvfrom(sockfd, msg, 999, 0, (struct sockaddr *)&current_remote_addr, &len);
        msg[n] = 0;
        printf("IP = %s, Port = %d, MSG = %s\n",
               inet_ntoa(current_remote_addr.sin_addr),
               ntohs(current_remote_addr.sin_port), msg);
        //sendto(sockfd, msg, n, 0, (struct sockaddr *)&current_remote_addr, len);
        
        bool alreadyConnectedUser = false;
        for (int i = 0; i < connectedPlayers; i++) {
          if (strcmp(inet_ntoa(users[i].addr.sin_addr),
                     inet_ntoa(current_remote_addr.sin_addr)) == 0 &&
              users[i].addr.sin_port == current_remote_addr.sin_port) {
            alreadyConnectedUser = true;
            continue;
          }
        }
        if (alreadyConnectedUser) {
            printf("Already connected user. Skipping...");
            continue;
        }

        user *u = users + connectedPlayers;
        u->addr = current_remote_addr;
        u->name = malloc(sizeof(char) * (n+1));
        strcpy(u->name, msg);
        u->lives = 0;
        connectedPlayers++;

        char *out_msg = connectedPlayers < NUMBER_OF_PLAYERS
            ? "In attesa di altri giocatori...\n"
            : "Tutti i giocatori sono pronti. Iniziamo!\n";
        assert(sendto(sockfd, out_msg, strlen(out_msg)+1, 0, (struct sockaddr *)&current_remote_addr, len) > 0);
    }

    // FASE 2 - THE GAME
    int turn = 0;
    bool wordGuessed = false;
    char *randomWord = TO_GUESS_WORDS[rand() % TO_GUESS_WORDS_COUNT];
    char *currentRandomWord = malloc(sizeof(char) * (strlen(randomWord)+1));
    for (int i = 0; i < strlen(randomWord); i++)
        currentRandomWord[i] = '_';
    currentRandomWord[strlen(randomWord)] = 0;

    printf("Siamo tutti! La parola che dovrà essere indovinata è \"%s\"\n", randomWord);
    while (!wordGuessed) {

        user* u = users + turn;

        char out_msg[500];
        sprintf(out_msg, "Amico mio %s, è il tuo turno! La parola è la seguente: %s\nProva a indovinare la parola o suggerire una lettera.\n", u->name, currentRandomWord);
        struct sockaddr_in current_remote_addr = u->addr;
        assert(sendto(sockfd, out_msg, strlen(out_msg)+1, 0, (struct sockaddr *)&current_remote_addr, len) > 0);
        // si dovrebbe controllare che l'ip sia quello...
        recvfrom(sockfd, msg, 999, 0, (struct sockaddr *)&current_remote_addr, &len);
        printf("recvfrom |%s|\n", msg);

        char guessedLetterLower =
            (msg[0] >= 'a' && msg[0] <= 'z') ? msg[0] - ('a' - 'A') : msg[0];
        if (strlen(msg) == 1) {
          printf("\tL'utente sta tentando la lettera %c\n", msg[0]);
          for (int i = 0; i < strlen(randomWord); i++) {
            char randomWordLetterLower =
                (randomWord[i] >= 'a' && randomWord[i] <= 'z')
                    ? randomWord[i] - ('a' - 'A')
                    : randomWord[i];
            if (guessedLetterLower == randomWordLetterLower)
              currentRandomWord[i] = randomWord[i];
            }
        } else {
          printf("\tL'utente sta tentano la parola %s\n", msg);
          bool allMatch = true;
          bool lengthsMatch = strlen(randomWord) != strlen(msg);
          if (lengthsMatch)
            for (int i = 0; i < strlen(randomWord); i++) {
              char randomWordLetterLower =
                  (randomWord[i] >= 'a' && randomWord[i] <= 'z')
                      ? randomWord[i] - ('a' - 'A')
                      : randomWord[i];
              char msgLower =
                  (msg[i] >= 'a' && msg[i] <= 'z')
                      ? msg[i] - ('a' - 'A')
                      : msg[i];
              if (randomWordLetterLower != msgLower) {
                allMatch = false;
              }
            }

          if (allMatch && lengthsMatch) {
            printf("L'utente ha indovinato la parola");
          }
        }

        turn = (turn + 1) % NUMBER_OF_PLAYERS;
    }

    close(sockfd);

    return 0;
}