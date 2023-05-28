/*
 * bst_simple.cpp
 */
#include <iostream>

using namespace std;

typedef struct nodo {
	int	value;
	struct nodo * left;
	struct nodo * right;
} nodo;

typedef nodo * ptr_nodo;

bool bst_find(ptr_nodo root, int value_to_find)
{
	ptr_nodo p = root;
	while (p != nullptr) {
		if (value_to_find == p->value)
			return true;
		if (value_to_find > p->value)
			p = p->right;
		else
			p = p->left;
	}
	return false;
}

void bst_insert(ptr_nodo & root, int value_to_insert)
{
	ptr_nodo p = root;
	ptr_nodo parent = nullptr;
	while (p != nullptr) {
		if (value_to_insert > p->value) {
			parent = p;
			p = p->right;
		}
		else {
			parent = p;
			p = p->left;
		}
	}
	
	ptr_nodo new_node = new nodo;
	new_node->value = value_to_insert;
	new_node->left = nullptr;
	new_node->right = nullptr;
	
	if (root == nullptr) {
		root = new_node;
	}
	else {
		if (value_to_insert > parent->value)
			parent->right = new_node;
		else
			parent->left = new_node;
	}
}

void visit_in_order(ptr_nodo root)
{
	if (root != nullptr) {
		visit_in_order(root->left);
		cout << root->value << " ";
		visit_in_order(root->right);
	}
}

void visit_pre_order(ptr_nodo root)
{
	if (root != nullptr) {
		cout << root->value << " ";
		visit_pre_order(root->left);
		visit_pre_order(root->right);
	}
}

void visit_post_order(ptr_nodo root)
{
	if (root != nullptr) {
		visit_post_order(root->left);
		visit_post_order(root->right);
		cout << root->value << " ";
	}
}

ptr_nodo find_max(ptr_nodo p)
{
	while (p && p->right != nullptr)
		p = p->right;
	return p;
}

ptr_nodo find_min(ptr_nodo p)
{
	while (p && p->left != nullptr)
		p = p->left;
	return p;
}

ptr_nodo deleteNode(ptr_nodo root, int key)
{
    // base case
    if (root == nullptr)
        return root;
 
    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->value)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->value)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node has no child
        if (root->left == nullptr and root->right == nullptr)
            return nullptr;
 
        // node with only one child or no child
        else if (root->left == nullptr) {
            ptr_nodo temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == nullptr) {
            ptr_nodo temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        ptr_nodo temp = find_min(root->right);
 
        // Copy the inorder successor's content to this node
        root->value = temp->value;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

int main(int argc, char **argv)
{
	ptr_nodo mybst = nullptr;
	
	bst_insert(mybst, 10);
	bst_insert(mybst, 5);
	bst_insert(mybst, 2);
	bst_insert(mybst, 30);
	bst_insert(mybst, 20);
	bst_insert(mybst, 15);
	bst_insert(mybst, 18);
	bst_insert(mybst, 40);

	// bst_insert(mybst, 35);
	// bst_insert(mybst, 1);
	// bst_insert(mybst, 3);
	// bst_insert(mybst, 37);
	// bst_insert(mybst, 11);
	// bst_insert(mybst, 22);
	
	visit_in_order(mybst); cout << endl;
	// visit_pre_order(mybst); cout << endl;
	// visit_post_order(mybst); cout << endl;
	
	cout << "Find 5: " << (int)bst_find(mybst, 5) << endl;
	cout << "Find 7: " << (int)bst_find(mybst, 7) << endl;
	cout << "Find 10: " << (int)bst_find(mybst, 10) << endl;
	
	mybst = deleteNode(mybst, 20);
	visit_in_order(mybst); cout << endl;
	
	return 0;
}

