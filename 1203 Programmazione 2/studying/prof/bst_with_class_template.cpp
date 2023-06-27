/*
 * bst_with_class.cpp
 */
 
 #include <iostream>

using namespace std;

template <typename K, typename D> class Nodo {
	K	key;
	D	data;
	Nodo * left;
	Nodo * right;
	
	Nodo * root;
	
	void _internal_insert(Nodo * & root, K & value_to_insert, D & data_to_insert);
	void _internal_visit_in_order(Nodo * root);
	bool _internal_find(Nodo * p, K value_to_find);
	void _internal_delete(Nodo * & root, K value_to_delete);
	Nodo * del_successor(Nodo * & root);
public:
	Nodo() : root(nullptr) { }; // costruttore dell'albero
	
	Nodo(K v, D d) : key(v), data(d), left(nullptr), right(nullptr) { };
	
	void insert(K value_to_insert, D data_to_insert);
	void visit_in_order();
	bool find(K value_to_find);
	void del(K value_to_delete);
	
};


template <typename K, typename D> 
void Nodo<K,D>::_internal_insert(Nodo * & root, K & value_to_insert, D & data_to_insert)
{
    if (root == nullptr) {
        root = new Nodo(value_to_insert, data_to_insert);
    }
    else {
        if (value_to_insert < root->key)
            _internal_insert(root->left, value_to_insert, data_to_insert);
        else
            _internal_insert(root->right, value_to_insert, data_to_insert);
    }
}


template <typename K, typename D> 
void Nodo<K,D>::insert(K value_to_insert, D data_to_insert)
{
	_internal_insert(root, value_to_insert, data_to_insert);
}

template <typename K, typename D> 
void Nodo<K,D>::_internal_visit_in_order(Nodo<K,D> * root)
{
	if (root != nullptr) {
		_internal_visit_in_order(root->left);
		cout << root->key << " : " << root->data << endl;
		_internal_visit_in_order(root->right);
	}
}


template <typename K, typename D> 
void Nodo<K,D>::visit_in_order()
{
	_internal_visit_in_order(root);
}


template <typename K, typename D> 
bool Nodo<K,D>::_internal_find(Nodo<K,D> * p, K value_to_find)
{
    if (p == nullptr)
        return false;
    else {
        if (value_to_find == p->key)
            return true;
        if (value_to_find > p->key)
            return _internal_find(p->right, value_to_find);
        else
            return _internal_find(p->left, value_to_find);
    }
}

template <typename K, typename D> 
bool Nodo<K,D>::find(K value_to_find)
{
	return _internal_find(root, value_to_find);
}


template <typename K, typename D> 
Nodo<K,D> * Nodo<K,D>::del_successor(Nodo<K,D> * & root)
{
    if (root->left == nullptr) {
        Nodo * p = root;
        root = root->right;
        return p;
    }
    else
        return del_successor(root->left);
}

template <typename K, typename D> 
void Nodo<K,D>::_internal_delete(Nodo<K,D> * & root, K value_to_delete)
{
    if (root == nullptr)
        return;

    if (root->key == value_to_delete) {
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
        root->key = successor->key;
        root->data = successor->data;
        delete successor;
        return;

    }
    else {
        if (value_to_delete > root->key)
            _internal_delete(root->right, value_to_delete);
        else
            _internal_delete(root->left, value_to_delete);
    }
}

template <typename K, typename D> 
void Nodo<K,D>::del(K value_to_delete)
{
	_internal_delete(root,value_to_delete);
}


int main(int argc, char ** argv)
{
	Nodo<int,string> mybst;
	
	mybst.insert(10,"aaa");
	mybst.insert(2, "bbb");
	mybst.insert(4, "ccc");
	mybst.insert(5, "ddd");
	mybst.insert(20, "eee");
	
	mybst.visit_in_order();
	
	cout << "Find 2 : " << mybst.find(2) << endl;
	cout << "Find 3 : " << mybst.find(3) << endl;
	cout << "Find 10 : " << mybst.find(10) << endl;
	
	mybst.del(2);
	mybst.visit_in_order();
}


