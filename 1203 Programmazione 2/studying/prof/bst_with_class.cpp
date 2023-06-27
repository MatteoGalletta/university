/*
 * bst_with_class.cpp
 */
 
 #include <iostream>

using namespace std;

class Nodo {
	int	value;
	Nodo * left;
	Nodo * right;
	
	Nodo * root;
	
	void _internal_insert(Nodo * & root, int value_to_insert);
	void _internal_visit_in_order(Nodo * root);
	bool _internal_find(Nodo * p, int value_to_find);
	void _internal_delete(Nodo * & root, int value_to_delete);
	Nodo * del_successor(Nodo * & root);
public:
	Nodo() : root(nullptr) { }; // costruttore dell'albero
	
	Nodo(int v) : value(v), left(nullptr), right(nullptr) { };
	
	void insert(int value_to_insert);
	void visit_in_order();
	bool find(int value_to_find);
	void del(int value_to_delete);
	
};


void Nodo::_internal_insert(Nodo * & root, int value_to_insert)
{
    if (root == nullptr) {
        root = new Nodo(value_to_insert);
    }
    else {
        if (value_to_insert < root->value)
            _internal_insert(root->left, value_to_insert);
        else
            _internal_insert(root->right, value_to_insert);
    }
}


void Nodo::insert(int value_to_insert)
{
	_internal_insert(root, value_to_insert);
}

void Nodo::_internal_visit_in_order(Nodo * root)
{
	if (root != nullptr) {
		_internal_visit_in_order(root->left);
		cout << root->value << " ";
		_internal_visit_in_order(root->right);
	}
}


void Nodo::visit_in_order()
{
	_internal_visit_in_order(root);
}


bool Nodo::_internal_find(Nodo * p, int value_to_find)
{
    if (p == nullptr)
        return false;
    else {
        if (value_to_find == p->value)
            return true;
        if (value_to_find > p->value)
            return _internal_find(p->right, value_to_find);
        else
            return _internal_find(p->left, value_to_find);
    }
}

bool Nodo::find(int value_to_find)
{
	return _internal_find(root, value_to_find);
}


Nodo * Nodo::del_successor(Nodo * & root)
{
    if (root->left == nullptr) {
        Nodo * p = root;
        root = root->right;
        return p;
    }
    else
        return del_successor(root->left);
}

void Nodo::_internal_delete(Nodo * & root, int value_to_delete)
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
            Nodo * p = root->left;
            delete root;
            root = p;
            return;
        }
        if (root->left == nullptr) {
            // no left subtree
            Nodo * p = root->right;
            delete root;
            root = p;
            return;
        }
        // mid-node, find successor
        Nodo * successor = del_successor(root->right);
        root->value = successor->value;
        delete successor;
        return;

    }
    else {
        if (value_to_delete > root->value)
            _internal_delete(root->right, value_to_delete);
        else
            _internal_delete(root->left, value_to_delete);
    }
}

void Nodo::del(int value_to_delete)
{
	_internal_delete(root,value_to_delete);
}


int main(int argc, char ** argv)
{
	Nodo mybst;
	
	mybst.insert(10);
	mybst.insert(2);
	mybst.insert(4);
	mybst.insert(5);
	mybst.insert(20);
	
	mybst.visit_in_order(); cout << endl;
	
	cout << "Find 2 : " << mybst.find(2) << endl;
	cout << "Find 3 : " << mybst.find(3) << endl;
	cout << "Find 10 : " << mybst.find(10) << endl;
	
	mybst.del(2);
	mybst.visit_in_order(); cout << endl;
}


