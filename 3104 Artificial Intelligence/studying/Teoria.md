---
type: university
date: 2024-10-17
subjectId: 3104
year: 3
semester: 1
---
#university #studying #subject-3104
### Teoria
> [!summary] Artificial Intelligence

da vedere:
- Complessità algoritmi di ricerca
- Ammissibilità, Ottimalità e Consistenza/Monotonia di A*

### 2. Intelligent Agents
- Agente intelligente
	- razionali
	- human-like
- Task Environment = PEAS = descrizione problema che risolve un agente:
	- definito da:
		- Performance Measure: the notion of desiderability
			- es. safe/fast/legal
		- Environment
		- Actuators
		- Sensors
	- dimensions:
		- unobservable/partially observable/fully observable
			- i sensori vedono l'intero ambiente? è necessario avere uno stato interno?
		- single agent/multi agent
			- multi agent = esistono altri agent (per agent si intende un oggetto il cui comportamento influenza la nostra performance)
			- multi agent può essere competitivo e cooperativo
		- deterministic/stochastic
			- se lo stato successivo dipende solo da quello attuale + azione
			- n.b. se partially observable potrebbe sembrare stocastico ma non è detto
			- stochastic = probabilità associata a stato
			- uncertain = più outcome (non c'è probabilità numerica) = causato da non deterministic oppure non fully observable
		- episodic/sequential
			- Per scegliere la prossima azione è importante la storia delle percezioni?
		- static/dynamic
			- Mentre l'agent pensa, l'ambiente cambia?
			- semidynamic: se il tempo influisce il performance score
		- discrete/continuos
			- dipende dal numero di stati e da cosa percepiscono i sensori
		- known/unknown
			- conosco gli stati causati dalle mie azioni?
- Tipi di agenti:
	- Simple reflex
		- sulla base di condizioni (if su sensori) scelgo l'azione
	- Model based reflex
		- memoria storico percezioni
		- predizione ambiente in base ad azione
	- Goal based
		- ha un obiettivo
		- si pensa: la prossima azione come influenzerà il mio obiettivo?
	- Utility based
		- si usa una funzione che associa allo stato un valore di "happiness". 
### 3. Solving Problems by Searching

### 4. Beyond Classical Search

### 5. Adversial Search



continua da: pg 206