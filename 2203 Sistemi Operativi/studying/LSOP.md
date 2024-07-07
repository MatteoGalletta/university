---
type: university
date: 2024-07-06
subjectId: 2203
year: 2
semester: 2
---
#university #studying #subject-2203
### LSOP
> [!summary] Sistemi Operativi

**Glossario:**
- LSOP = Laboratorio di Sistemi Operativi Protocol
- xd
 
### Bingo (20/02/2024)
#### V1 con barriere/cond/mutex
*non funziona*

--strutture --
struct_condivisa con
- ultimo_numero_estratto
- stato (ATTESA_ESTRAZIONE, ATTESA_CONTROLLO)
- is_cinquina_available
- mutex
- cond_aspetta_estrazione
- cond_aspetta_controllo
- barrier_controllo_effettuato

struct_giocatore con
- card
- vincita = (NULL, CINQUINA, BINGO)
- struct_condivisa

-- flusso --
main (dealer):
- crea struct_condivisa
- crea n struct_giocatore
- crea n thread passandogli struct_giocatore
- 
- barrier_init(barrier_controllo_effettuato, n)
- 
- in loop:
	- genera nuovo numero
	- stato = ATTESA_ESTRAZIONE
	- cond_broadcast(cond_aspetta_estrazione)
	- while (stato != ATTESA_CONTROLLO)
		- cond_wait(cond_aspetta_controllo)
	- controllo se ci sono vincitori (cinquine o bingo)
	- se c'è cinquina stampo la vincita
	- se c'è un bingo, stampo la vincita e uccido tutti

i-esimo thread:
- while (stato != ATTESA_ESTRAZIONE)
	- cond_wait(cond_aspetta_estrazione)
- controlla e aggiorna la card
- 
- se ha fatto cinquina e is_cinquina_available: vincita = CINQUINA
- else se ha fatto bingo:
	- vincita = BINGO
	- stato = ATTESA_CONTROLLO
	- cond_signal(cond_aspetta_controllo)
- else:
	- barrier_wait(barrier_controllo_effettuato)
	- if (PTHREAD_BARRIER_SERIAL_THREAD)
		- stato = ATTESA_CONTROLLO
		- cond_signal(cond_aspetta_controllo)

#### V2 con semafori/mutex

-- strutture--
struct_condivisa con
- sem_t wait_card_arrival
- sem_t wait_card_extraction
- sem_t card_extraction_done
- sem_t wait_others
- ultimo_numero_estratto

struct_giocatore con
- cards
- vincita = (NULL, CINQUINA, BINGO)
- struct_condivisa

-- flusso --
dealer
```c
crea struct_condivisa shared
sem_init(shared.wait_card_arrival, 0)

for (player in players) {
	crea struct_giocatore
	struct_giocatore = new card
	
	pthread_create(struct_giocatore)
	wait(wait_card_arrival)
}

is_cinquina_available = false
sem_init(shared.wait_card_arrival, 0)
sem_init(shared.wait_card_extraction, 0)
sem_init(shared.card_extraction_done, 0)
sem_init(shared.wait_others, 0)

while (true) {

	struct_condivisa.ultimo_numero_estratto = random()

	for (player in players)
		post(shared.wait_card_extraction)

	player* winner_player = NULL
	for (player in players) {
		sem_wait(shared.card_extraction_done)
		if (shared.is_cinquina_available and player.vincita == CINQUINA and player == NULL)
			winner_player = &player
		if (player.vincita == BINGO and player == NULL)
			winner_player = &player
	}
	
	for (player in players) {
		sem_post(shared.wait_others)
	}

	if (winner_player != NULL) {
		shared.is_cinquina_available = false
		if (winner_player->vincita == CINQUINA) {
			print "Px: Carta con cinquina:" winner_player->card
		}
		else if (winner_player->vincita == BINGO) {
			exit(0)
		}
		
	}

}
```

player
```c
stampa card
sem_post(wait_card_arrival)

while (true) {
	sem_wait(shared.wait_card_extraction)
	controlla se c'è ultimo_numero_estratto in cards
	if (cinquina)
		vincita = CINQUINA
	else if (bingo)
		vincita = BINGO
	else
		vincita = NONE

	sem_post(shared.card_extraction_done)
	sem_wait(shared.wait_others)
}
```

### Calc-Verifier-2 (02/02/2024)

-- strutture --
```c
struct s_shared {
	int op1, op2, result;
	char op;
	pthread_t tid; // richiedente

	pthread_mutex_t mutex;
	sem_t sem_wait_op;
	sem_t sem_done_op;
	sem_t sem_wait_others;
}

struct s_operation {
	char op;
	int (*fun)(int, int);
	
	s_shared *shared_ptr;
}

struct s_calc {
	int r_attended;
	int r_obtained;
	pthread_t tid;

	s_shared *shared_ptr;
}
```

-- flusso --
main
```c

int add(int op1, int op2) { return op1 + op2; }
int sub(int op1, int op2) { return op1 - op2; }
int mul(int op1, int op2) { return op1 * op2; }

s_shared shared;
s_operation operations[3] = {
	{ '+', add, &shared },
	{ '-', sub, &shared },
	{ '*', mul, &shared }
};
s_calc calcs[n];
calc.shared_ptr = &shared;
for operations[i].shared_ptr = &shared;

sem_init(shared.sem_wait_op, 0, 0);
sem_init(shared.sem_done_op, 0, 0);
sem_init(shared.sem_wait_others, 0, 0);

for (i=0 to n) {
	pthread_create(&calcs[i].tid, calcscalc, NULL, &calcs[i]);
}

for (i=0 to 3) {
	pthread_create(operation, operations[i]);
}

for (i=0 to n) {
	pthread_join(calcs[i].tid, NULL);
}

// controlla r_attended vs r_obtained

```

calc (n per file)
```c

f = apri file
int op1, op2;
foreach (riga) {

	if (riga is first) {
		op1 = riga;
		continue;
	}

	/*
	char row[101];
	fgets(row, 100, f);
	if (sscanf(row, "%c %d") == 2)
	*/

	if (riga is last) { // come capirlo?
		data.r_attended = riga;
		continue;
	}

	pthread_mutex_lock(&shared.mutex);

	(op, valore) = riga;
	
	op2 = valore

	shared.op1 = op1;
	shared.op2 = op2;
	shared.op = op;
	shared.tid = gettid();

	// wait
	for (i=0 to 3)
		sem_post(shared.sem_wait_op)
	for (i=0 to 3)
		sem_wait(shared.sem_done_op)
	for (i=0 to 3)
		sem_post(shared.sem_wait_others)

	op1 = shared.result

	pthread_mutex_unlock(&shared.mutex);
}

data.r_obtained = op1;

```

operation (3)
```c
while (true) {

	sem_wait(shared.sem_wait_op);

	if (data.op == shared.op)
		shared.result = data.fun(shared.op1, shared.op2);
	
	sem_post(shared.sem_done_op);
	sem_wait(shared.sem_wait_others);
}
```

