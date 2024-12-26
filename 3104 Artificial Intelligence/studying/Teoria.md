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
	- razionali (-> "fare la cosa giusta" -> "ottenere il massimo grado di successo")
	- human-like
- Agente:
	- può essere definito coma una funzione $f:P^{*} \to A$
		- $P^{*}$: storia delle percezioni
		- $A$: azione da compiere
	- percepisce l'ambiente tramite sensori
	- agisce sull'ambiente tramite attuatori
#### Task Environment
Task Environment = PEAS = descrizione problema che risolve un agente:
- definito da:
	- Performance Measure: the notion of desiderability
		- es. safe/fast/legal
	- Environment
	- Actuators
	- Sensors
- dimensions:
	- unobservable/partially observable/fully observable
		- i sensori vedono l'intero ambiente? è necessario avere uno stato interno per tenere traccia dell'ambiente esterno? O è sufficiente utilizzare i sensori?
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
		- semi-dynamic: se il tempo influisce il performance score
	- discrete/continuous
		- dipende dal numero di stati e da cosa percepiscono i sensori
	- known/unknown
		- conosco gli stati causati dalle mie azioni?
#### Tipi di agenti
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
#### Learning agent
- diviso in componenti:
	- performance element: l'agent vero e proprio (simple, model based, ecc)
	- critic: tramite i percettori restituisce la performance dell'agente
	- learning element: prende le critics e modifica il performance element per tentare di aumentare la performance
	- problem generator: individua le azioni per ottenere nuove esperienze
#### Agent components
- atomic
	- each state is a black box
- factored
	- each state is represented by variables or attributes
- structured
	- each state contains relationships - representation underlies a relational database
## Problem-solving
### 3. Solving Problems by Searching
#### Problem components
- Initial state
- Actions: given a state, returns all the actions possibile
- Transition Model: given a state and an action, returns the result state (a.k.a. successor)
	- State Space: the set of all reachable states from the initial state
	- Search Tree: a graph with actions as branches and states as nodes
- Goal Test: determines if the a given state is a goal state.
- Path Cost: assigns a numeric cost to each path
#### Search tree
- frontier: set of nodes available for graph exploration
- Tree-Search: contains redundant paths
- Graph-Search: uses an "explored set" to avoid loops.
#### Measuring Problem-solving performance:
- Types:
	- Completeness: is the algorithm guaranteed to find a solution when there is one?
	- Optimality: does the strategy find the optimal (lowest cost) solution?
	- Time complexity
	- Space complexity
- Variables
	- $b$ "branching factor": maximum number of successors of a nodes
	- $d$ "depth": shallowest/closest goal node
	- $m$ "maximum length": maximum length of any path in the graph-search tree
#### Uninformed Search: we have only access to problem definition
##### Breath-first search
Expands the shallowest nodes first.
- Complete
- Optimal for unit step costs
- Exponential Space Complexity of $O(b^{d})$ ("dominated by frontier size")
##### Uniform-cost search
Expands the lowest path cost node (the frontier is implemented with a priority queue).
- Optimal for any cost
- Is not necessary better than BFS:
	- it has to explore all the low-cost edges before reaching the goal.
	- it requires all the generated costs (to get the minimum)
##### Depth-first search
Expands the deepest node.
- Complete in the graph-search version (no cycles)
- Not Optimal
- Linear Space Complexity $O(bm)$ (where $m$ is the deepest path)
	- we can reduce this  to $O(m)$ by expanding only the successor
##### Depth-limited search
Expands the deepest node up to $l$.
- same as $DFS$, but stops when we reach depth $l$
- Not Complete
- Not Optimal
- Lineare Space Complexity
##### Iterative deepening depth-first search
Uses Depth-limited search with $l$ starting from 0. It increases the limit until a goal is found. It's useful when we have limited memory. We could use BFS until memory finishes. Then switch to iterative deepening depth-first search.
- Complete
- Optimal for unit step costs (as BFS)
- Linear Space Complexity
- Time complexity comparable to BFS (in terms of $O$).
##### Bidirectional Search
Starts two searches in parallel, one from the start and the other from the goal, until they meet (the frontiers touch - frontiers intersection is not null anymore). It is efficient since $b^{\frac{d}{2}} + b^{\frac{d}{2}}$ is much smaller than $b^{d}$.
- Complete
- Not Optimal (even if using BFS from both sides - can be fixed using a constant time check)
- Exponential complexity of $O(b^{\frac{d}{2}})$
#### Informed Search
We have access to a heuristic function that estimates the path cost of a solution.
##### Intuition (general Best-First Search):
- until now, we used the path cost function $g$. In informed search, we introduce a heuristics function $h$.
- $h(n)$: estimated cost of the cheapest path from the state at node $n$ to the goal state. Compared to $g$, $h$ depends only by the state of the node $n$.
- we start from the general Tree-Search or Graph-Search algorithm and we use a new function $f$ instead.
- $f$ is a function that *takes in count* (differently depending on the search strategy) the heuristics function.
- The general implementation is the same as the Uniform-Cost Search changing the path cost function from $g$ to $f$.
##### Greedy Best-First Search:
- $f(n)=h(n)$
- Complete in the graph-search version with *finite* space
- Not Optimal
- Efficient
##### A\* Search
- $f(n)=g(n)+h(n)$
- Complete
- Optimal if some condition match:
	- $h$ must be admissible: $h$ must never overestimate the cost to reach the goal. $h$ must be *optimistic*.
	- $h$ must be consistent: the triangle inequality $h(n) \leq cost(n, a, n') + h(n')$ must be respected.
	- $h(n) \text{ is consistent} \implies h(n) \text{ is admissible}$
	- A* Tree-Search is optimal if $h$ is admissible.
	- A* Graph-Search is optimal if $h$ is consistent.
- It uses a lot of space, making it unsuitable for large state space problems.
##### Iterative Deepening A\* Search:
It's essentially iterative deepening depth-first search with the newly defined $f$ function as depth.
##### Recursive Best-First Search:
Similar to IDA*, but it uses less memory. IDA* stores every node to select the node with lowest $f$. In RBFS instead, we just store the best alternative from any ancestor to the current node.
It uses linear space, is complete and optimal.
It can *change his mind* multiple times, so time complexity is hard to define.
##### Simplified Memory-bounded A* Search:
Aims to improve RBFS using more space if available.
It's an hybrid between A* and RBFS. Uses A* until no more space is available to allocate a new node. Then, it drops the worst node and just saves the $f$ value, "switching to RBFS". *Details not explained*
This is a variant of Memory-bounded A* Search, which is not explained.
### 4. Beyond Classical Search
#### Hill-Climbing Search
- sometimes called greedy local search. It takes as successor the node nearest to the goal. It doesn't track nodes using a tree, it just moves between nodes.
- Local Maxima is the problem of this algorithm: it's not the global maximum and it gets stuck
#### Simulated Annealing
- Aims to reduce the Local Maxima problem of Hill-Climbing Search.
- It uses a temperature variable that decreases over time (over iterations).
- The algorithm chooses randomly the successor node: if it has a better cost, it gets chosen, otherwise it gets accepted only by a probability that depends on the temperature, allowing to choose more worse nodes at the beginning.
### 5. Adversarial Search
#todo
### 6. Constraint Satisfaction Problem
Until now we assumed all the states were black boxes.
A constraint satisfaction problem consists of:
- X: a set of variables, $\{ X_{1}, \dots, X_{n} \} {}$.
- D: a set of domains, $\{D_{1}, \dots, D_{n} \}$, one for each variable.
	- $D_{i}$ is a set of allowable values $\{ v_{1}, \dots, v_{k}\}$ for $X_{i}$.
- C: a set of constraints that specify allowable combinations of values.
	- $C_{i}$ is a pair $\langle\text{scope}, \,\text{relation}\rangle$
		- $\text{scope}$: tuple of variables ($X_{i}$) that partecipate in the constraint
		- $\text{relation}$: set of values (each value is a tuple of $D_{i}$) that variables in $scope$ can take on.
## Knowledge, reasoning, and planning
### 7. Logical Agents
### 8. First-Order Logic
### 9. Inference in First-Order Logic



continua da: pg 206