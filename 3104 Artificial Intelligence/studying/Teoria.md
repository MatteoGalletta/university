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

libro: Artificial Intelligence - S. Russell, P. Norvig
## Artificial Intelligence
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
- Learning agent
	- diviso in componenti:
		- performance element: l'agent vero e proprio (simple, model based, ecc)
		- critic: tramite i percettori restituisce la performance dell'agente
		- learning element: prende le critics e modifica il performance element per tentare di aumentare la performance
		- problem generator: individua le azioni per ottenere nuove esperienze
- Agent components
	- atomic
		- each state is a black box
	- factored
		- each state is represented by variables or attributes
	- structured
		- each state contains relationships - representation underlies a relational database
## Problem-solving
### 3. Solving Problems by Searching
- Problem components
	- Initial state
	- Actions: given a state, returns all the actions possibile
	- Transition Model: given a state and an action, returns the result state (a.k.a. successor)
		- State Space: the set of all reachable states from the initial state
		- Search Tree: a graph with actions as branches and states as nodes
	- Goal Test: determines if the a given state is a goal state.
	- Path Cost: assigns a numeric cost to each path
- Search tree:
	- frontier: set of nodes available for graph exploration
	- Tree-Search: contains redundant paths
	- Graph-Search: uses an "explored set" to avoid loops.
- Measuring Problem-solving performance:
	- Types:
		- Completeness: is the algorithm guaranteed to find a solution when there is one?
		- Optimality: does the strategy find the optimal (lowest cost) solution?
		- Time complexity
		- Space complexity
	- Variables
		- $b$ "branching factor": maximum number of successors of a nodes
		- ${} d$ "depth": shallowest/closest goal node
		- $m$ "maximum length": maximum length of any path in the graph-search tree
### 4. Beyond Classical Search

### 5. Adversarial Search

### 6. Constraint Satisfaction Problem
## Knowledge, reasoning, and planning
### 7. Logical Agents
### 8. First-Order Logic
### 9. Inference in First-Order Logic



continua da: pg 206