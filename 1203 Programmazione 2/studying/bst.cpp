#include <iostream>

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data, Node* left, Node* right)
		: data(data), left(left), right(right) {}
	
	Node() : data(0), left(nullptr), right(nullptr) {}
};


class BST {
protected:
	Node* root;

	Node* get_min(Node *node) {
		while (node != nullptr && node->left != nullptr)
			node = node->left;
		return node;
	}
	Node* remove(Node* node, int value) {
		
		if (value > node->data)
			node->right = remove(node->right, value);
		else if (value < node->data)
			node->left = remove(node->left, value);
		else {
			if (node->left == nullptr && node->right == nullptr) {
				delete node;
				return nullptr;
			}

			if (node->left == nullptr || node->right == nullptr) {
				Node* nextChild = (node->left == nullptr)
					? node->right : node->left;
				delete node;
				return nextChild;
			}

			Node* successorNode = get_min(node->right);
			node->data = successorNode->data;
			node->right = remove(node->right, node->data);
		}

		return node;
	}
	void inorder(Node* node) {
		if (node == nullptr)
			return;
		
		inorder(node->left);
		std::cout << node->data << " ";
		inorder(node->right);
	}
public:
	BST() : root(nullptr) {}

	void insert(int value) {
		Node* parent = nullptr;
		Node* iterator = root;
		while (iterator != nullptr) {
			parent = iterator;
			iterator = (value > iterator->data)
				? iterator->right
				: iterator->left;
		}
		
		Node* newNode = new Node(value, nullptr, nullptr);
		if (parent == nullptr)
			root = newNode;
		else {
			if (value > parent->data)
				parent->right = newNode;
			else
				parent->left = newNode;
		}
	}

	void remove(int value) {
		root = remove(root, value);
	}

	void inorder() {
		inorder(root);
	}
};

int main() {

	BST bst;
	bst.insert(2);
	bst.insert(5);
	bst.insert(3);
	bst.insert(1);
	bst.insert(4);
	bst.insert(8);
	bst.insert(9);
	bst.insert(6);
	bst.insert(10);

	bst.inorder();
	bst.remove(9);
	bst.inorder();
}