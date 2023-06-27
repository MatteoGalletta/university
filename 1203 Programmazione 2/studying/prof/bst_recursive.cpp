/*
 * bst_recursive.cpp
 */
#include <iostream>

using namespace std;

typedef struct nodo {
	int	value;
	struct nodo * left;
	struct nodo * right;
} nodo;

typedef nodo * ptr_nodo;

bool bst_find(ptr_nodo p, int value_to_find)
{
    if (p == nullptr)
        return false;
    else {
        if (value_to_find == p->value)
            return true;
        if (value_to_find > p->value)
            return bst_find(p->right, value_to_find);
        else
            return bst_find(p->left, value_to_find);
    }
}

void bst_insert(ptr_nodo & root, int value_to_insert)
{
    if (root == nullptr) {
        root = new nodo;
        root->value = value_to_insert;
        root->left = nullptr;
        root->right =  nullptr;
    }
    else {
        if (value_to_insert < root->value)
            bst_insert(root->left, value_to_insert);
        else
            bst_insert(root->right, value_to_insert);
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

ptr_nodo del_successor(ptr_nodo & root)
{
    if (root->left == nullptr) {
        ptr_nodo p = root;
        root = root->right;
        return p;
    }
    else
        return del_successor(root->left);
}

void bst_delete(ptr_nodo & root, int value_to_delete)
{
    if (root == nullptr)
        return;

    if (root->value == value_to_delete) {
        if (root->right == nullptr && root->left == nullptr) {
            // leaf node
            delete root;
            root = nullptr;
            return;
        }
        if (root->right == nullptr) {
            // no right subtree
            ptr_nodo p = root->left;
            delete root;
            root = p;
            return;
        }
        if (root->left == nullptr) {
            // no left subtree
            ptr_nodo p = root->right;
            delete root;
            root = p;
            return;
        }
        // mid-node, find successor
        ptr_nodo successor = del_successor(root->right);
        root->value = successor->value;
        delete successor;
        return;

    }
    else {
        if (value_to_delete > root->value)
            bst_delete(root->right, value_to_delete);
        else
            bst_delete(root->left, value_to_delete);
    }
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
	bst_insert(mybst, 35);
	bst_insert(mybst, 1);
	bst_insert(mybst, 3);
	bst_insert(mybst, 37);
	bst_insert(mybst, 11);
	bst_insert(mybst, 22);
	
	visit_in_order(mybst); cout << endl;
	//visit_pre_order(mybst); cout << endl;
	//visit_post_order(mybst); cout << endl;
	
	cout << "Find 5: " << (int)bst_find(mybst, 5) << endl;
	cout << "Find 7: " << (int)bst_find(mybst, 7) << endl;
	cout << "Find 10: " << (int)bst_find(mybst, 10) << endl;
	
	bst_delete(mybst, 35);
	bst_delete(mybst, 22);
	bst_delete(mybst, 10);
	visit_in_order(mybst); cout << endl;
	
	return 0;
}

