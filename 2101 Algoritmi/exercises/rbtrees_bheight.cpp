/*Red-Black Trees: calcolo della b-altezza
Si fornisca una procedura ricorsiva che, preso in input il puntatore ad un nodo x di un albero rosso-nero, restituisca l'altezza nera del nodo x. Si fornisca la procedura più efficiente in grado di effettuare questo calcolo e si discuta la sua complessità asintotica.
*/

struct Node {
	Node* left;
	Node* right;
	Node* parent;
	int value;
	bool isBlack;
}

// Theta(n) = 2Theta(n/2) + O(1)
int getRBTreeBlackHeight(Node *x) {
	if (x == nullptr) {
		return 0;
	}
	
	return (x->isBlack ? 1 : 0) + max(
		getRBTreeBlackHeight(x->left),
		getRBTreeBlackHeight(x->right));
}

