
int treeHeight(Node* x) {
	if (x == nullptr)
		return 0;
	return max(treeHeight(x->left), treeHeight(x->right)) + 1;
}

