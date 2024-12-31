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
	- #todo see proofs
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
Now states are [[#Agent components|factored]], so if we're able to formulate a problem as CSP we can get more efficient solutions.
A constraint satisfaction problem consists of:
- $X$: a set of variables, $\{ X_{1}, \dots, X_{n} \}$.
- $D$: a set of domains, $\{D_{1}, \dots, D_{n} \}$, one for each variable.
	- $D_{i}$ is a set of allowable values $\{ v_{1}, \dots, v_{k}\}$ for $X_{i}$.
- $C$: a set of constraints that specify allowable combinations of values.
	- $C_{i}$ is a pair $\langle\text{scope}, \,\text{relation}\rangle$
		- $\text{scope}$: tuple of variables ($X_{i}$) that partecipate in the constraint
		- $\text{relation}$: set of values (each value is a tuple of $D_{i}$) that variables in $scope$ can take on.

In a given state, we can set some values to one of more variables. Those are called **assignments**.
- An assignment is **consistent** if it doesn't violate any constraint.
- An assignment is **complete** if it's consistent and every variable is assigned.
- An assignment is **partial** if it's consistent and at least one variable is assigned.

We can represent a CSP with a **Constraint Chart**:
- Nodes are the variables of the problem $X$.
- Edges between two nodes exists if there's at least a constraint $C$ that includes both of the nodes as $\text{scope}$.

#### N-Queens example
$$\begin{align}
X&=\{ Q_{1}, Q_{2}, \dots, Q_{n}\} \\
D&=\{ 1, 2, \dots, n \} \\
C&=\{ Q_{i} \neq Q_{k}, \quad|Q_{i} - Q_{k} | \neq  |i-k|\} \quad\small{\text{ technically not respecting formal definition}}
\end{align}
$$

#### Implementation with Search
We can implement any CSP using the [[#3. Solving Problems by Searching|Search]]. The entities are defined as follows:
- Initial state: all the variables are unassigned.
- Actions: assign a value to a variable
- Goal function: the variables assignment is **complete**.

In each state, we store:
- The $\small\text{UNASSIGNED}$ list: all the variables not assigned.
- The $\small\text{ASSIGNED}$ list: all the variables assigned.
- Additionally, for every variable:
	- $\small\text{NAME}$: *not really useful for the algorithm itself*
	- $\small\text{DOMAIN}$: $D_{i}$
	- $\small\text{VALUE}$: the current value, if present.

Constraints could be represented as sets or as functions that check for validity.

We can use DFS as search algorithm.
- $m=n$ (number of variables)
- ${} d=n$ (number of variables)
- $b=\sum\limits_{i} |D_{i}|$

The constraint could be redundant. We can apply a series of reductions to simplify the constraints.
#### Consistency
These can be used to reduce the amount of legal values and could potentially find the solution directly.
- Node Consistency:
	- we consider the unary constraints.
	- this is straightforward: we iterate all the variables and exclude the values in the domain that don't match the unary constraints.
- Arc Consistency:
	- we consider the binary constraints
	- we say $X_{i}$ is arc-consistent to $X_{j}$ if for every value $D_{i}$ there is some value in $D_{j}$ that satisfies the binary constraint on the arc $(X_{i}, X_{j})$
	- *there aren't useless values in $D_{i}$*
	- A real implementation algorithm is called $\text{AC-3}$
- Path Consistency
	- we consider the ternary constraints
	- "A two-variable set $\{X_{i}, X_{j} \}$ is path-consistent with respect to a third variable $X_{m}$ if, for every assignment $\{X_{i} = a, X_{j} = b\}$ consistent with the constraints on $\{X_{i} , X_{j} \}$, there is an assignment to $X_{m}$ that satisfies the constraints on $\{X_{i}, X_{m} \}$ and $\{X_{m}, X_{j} \}$"
	- A real implementation algorithm is called $\text{PC-2}$
- $K$-Consistency
	- it's the generalisation of the previous reductions
		- $K=1$ -> Node
		- ${} K=2 {}$ -> Arc
		- $K=3$ -> Path

If we impose $K$-Consistency with $K=|X|$, we just get the solution, but this is exponentially expensive.
#### Backtracking Search
We use DFS with fixed assignment order: variable assignment is a commutative operation, doing this ensures getting a faster algorithm.
The algorithm is recursive and it does the following: iterates all values of all variables in $X$ and searches using the following criteria:
- It returns failure if the state is inconsistent (to let the caller iterate the other values)
- It continues until the values are finished (there's no solution) or the assignment is complete (the problem has been solved).
- For each variable it imposes a certain level of consistency, depending on the problem ^a6a0fe
	- note we do this **before** performing the search.

If we need to just find a solution, we can apply some ordering tweaks to improve performance.
Of course, if we need all the solutions, ordering doesn't matter: we have to explore the whole graph.
##### Variables ($X$) Order
How do we order the iterated variables?
-  Minimum Remaining Values (MRV) Heuristics:
	- The variables chosen first are the ones with fewer legal values
	- a.k.a. "fail-first" heurstic -> if we found a variable fails, we can avoid checking other permutations on the other variables.
	- This fails if the variables have the same amount of legal values.
- Degree Heuristics:
	- The variables chosen first are the ones involved in the largest number of constraints.
We could combine both of the heuristics: default to MRV and switch to Degree Heuristics in case of legal values amount equality.

##### Domain $D_{i}$ values Order 
We then need an heuristic to iterate the values in the domain of the selected variable in a more efficient manner.
- Least Constraining Value:
	- we apply the same (but opposite) logic of MRV. We choose the values that rule out the fewest amount of choices for the neighboring variables in the constraint graph.

##### Forwarding Checking
**Inference**: imposing a level of consistency to a variable. 
Whenever a variable is assigned, we can perform a simple form of *inference* called Forward Checking: applying arc-consistency for it. Only useful if we don't already do it in the [[#^a6a0fe|preprocessing]] step 

#### Local Search
Instead of iterating all the values in all the variables, we select a random variable that violates some constraint.
This algorithm can use an heuristics called min-conflicts which selects the variable that violates the minimum amount of constraint conflicts.

This works very well for big problems, because it doesn't depend by the problem size.
## Knowledge, reasoning, and planning
### 7. Logical Agents
Now, agents will use Logic. Instead of working with states and having `code` to define the actions, now we use logic.
We use a Knowledge Base (KB), which is a set of sentences.
The knowledge base contains sentences that can either be axioms (taken for granted) or derived (from other sentences).
It's possibile to interact with the knowledge base with two operations:
- `TELL`: a way to add a sentence
- `ASK`: a way to query what is known.
The *derivation* is a way of *inference*, and is hidden behind the `TELL` and `ASK` operations.

An agent starts maintains a knowledge base, which at start may contain some background knowledge.
Each time an agent is called, it performs the following operations:
1. `MAKE-PERCEPT-SENTENCE`: it uses `TELL` and it constructs a sentence asserting that the agent perceived the given percept at the given time
2. `MAKE-ACTION-QUERY`: it `ASK`s what action should be done at the current time
3. `MAKE-ACTION-SENTENCE`: constructs a sentence asserting that the chosen action was executed

```pseudocode
function KB-AGENT( percept ) returns an action
	persistent:
		KB # a knowledge base
		t #, a counter, initially 0, indicating time
	
	TELL(KB, MAKE-PERCEPT-SENTENCE(percept, t))
	action ← ASK(KB, MAKE-ACTION-QUERY(t))
	TELL(KB, MAKE-ACTION-SENTENCE(action,t ))
	t ← t + 1
	
	return action
```

This approach is *declarative* (not *procedural* as we used before). We use the **knowledge level** just by specifying the desired goal, when querying we don't know how the **implementation level** works, since it's independent.

*details about logic and propositional logic already covered in **Strutture Discrete** and **Fondamenti di Informatica** subjects*.

How can we prove a sentence $\alpha$ is true in some KB?
We can either:
1. Iterate the truth table
2. Generate the derivation sequence

| Language            | Ontological Commitment<br>(what exists in the world) | Epistemological Commitment<br>(what an agent believes about facts) |
| ------------------- | ---------------------------------------------------- | ------------------------------------------------------------------ |
| Propositional logic | facts                                                | true/false/unknown                                                 |
| First-order logic   | facts, objects, relations                            | true/false/unknown                                                 |
| Temporal logic      | facts, objects, relations, times                     | true/false/unknown                                                 |
| Probability theory  | facts                                                | degree of belief ∈ [0, 1]                                          |
| Fuzzy logic         | facts with degree of truth ∈ [0, 1]                  | known interval value                                               |

### 8. First-Order Logic
This kind of logic allows us to represent the world in an *easier way*. Propositional Logic isn't suitable to represent knowledge of complex environments. First-Order Logic is sufficiently expressive to represent a good deal of our commonsense knowledge.
#### Base Elements
- Constant symbols: objects (e.g. `Richard` or `John`)
- Predicate symbols: relations (e.g. `Person`, `King` or `Crown`)
- Function symbols: functions (e.g. `Brother`, `AgeOf`, `SquareRoot`)
- Variables: $a, x, s, \dots$
- Connectors: $\lor, \land, \lnot, \implies, \iff$
- Quantifier: $\forall, \exists$
- Equality: $=$

Difference between predicate and function symbols:
- functions *return* a value, predicate are relations among values in a tuple of objects.
- $Red(x)$ is a predicate since it just asserts $x$ is red.
- $FatherOf(x)$ is a function since it returns the father of $x$.
	- $IsFatherOf(x, y)$ could be a predicate if it meant "$x$ is the father of $y$"
#### General Rules for Exercises
- $\forall x \forall y = \forall y \forall x$
- $\exists x \exists y = \exists y \exists x$
- $\exists x \forall y \neq \exists y \forall x$
- $(\forall x) f(x) = (\lnot \exists x)\lnot f(x)$
- $(\exists x) f(x) = (\lnot \forall x)\lnot f(x)$
#### Universal Elimination
We remember the **Modus Ponens** inference rule: $\frac{\alpha, \alpha \implies \beta}{\beta}$
The **Universal Elimination** is useful when we're dealing with quantifiers: $\frac{(\forall x) \alpha}{\alpha \{ x / \tau \}}$
Of course, $\tau$ must be a sentence (and not a variable)
We call $\{ x / t\}$ **unifier** and is often referred to as  $\sigma$.
This uses the concept of **substitution**.

We need something to understand that $Knows(John, x) = Knows(John, Jane)$.
We need a process that finds $\{x / Jane\}$.
We call this process **unification** - it's a function that returns a unifier, if such exists:
$$\text{UNIFY}(Knows(John, x), \,Knows(John, Jane)) = \{x/Jane\}$$
### 9. Inference in First-Order Logic
We have our KB. In practice, how do we *apply* inference?
#### Forward Chaining Algorithm
#todo
#### Backward Chaining Algorithm
#todo

## Uncertain knowledge and reasoning
### 13. Quantifying Uncertainty
### 16. Making Simple Decisions
## Learning
### 18. Learning From Examples
