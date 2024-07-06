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

### Calc-Verifier-2 (02/02/2024)

-- strutture --
struct_operazione
- op1
- op2
- thread_richiamante
- sem_mutex
struct_condivisa
- struct_operazione add, sub, mul;
struct_calc
- file_name
- risultato_atteso
- risultato_ottenuto
- struct_condivisa
- sem_waiting_finish
struct_op
- struct_condivisa


-- flusso --
main
```
int mul(int op1, int op2) { return op1 * op2; }
struct_operazione mul = { .op = mul };
```

calc

operation
- wait(sem_mutex)
- 

