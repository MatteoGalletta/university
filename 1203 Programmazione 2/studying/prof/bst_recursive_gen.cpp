/*
 * bst_recursive_gen.cpp
 */
#include <iostream>
#include <string>

using namespace std;

template <typename K, typename D> class Node {
public:
	K key;
	D data;
	Node<K,D> * left;
	Node<K,D> * right;
	Node(K _key, D _data) : key(_key), data(_data), left(nullptr), right(nullptr) { };
};

template <typename K, typename D> bool bst_find(Node<K,D> * p, K value_to_find)
{
    if (p == nullptr)
        return false;
    else {
        if (value_to_find == p->key)
            return true;
        if (value_to_find > p->key)
            return bst_find<K,D>(p->right, value_to_find);
        else
            return bst_find<K,D>(p->left, value_to_find);
    }
}

template <typename K, typename D> void bst_insert(Node<K,D>*  & root, K value_to_insert, D data_to_insert)
{
    if (root == nullptr) {
        root = new Node<K,D>(value_to_insert, data_to_insert);
    }
    else {
        if (value_to_insert < root->key)
            bst_insert<K,D>(root->left, value_to_insert, data_to_insert);
        else
            bst_insert<K,D>(root->right, value_to_insert, data_to_insert);
    }
}

template <typename K, typename D> void visit_in_order(Node<K,D> * root)
{
	if (root != nullptr) {
		visit_in_order<K,D>(root->left);
		cout << root->key << ":" << root->data << " ";
		visit_in_order<K,D>(root->right);
	}
}

template <typename K, typename D> void visit_pre_order(Node<K,D> * root)
{
	if (root != nullptr) {
		cout << root->key << ":" << root->data << " ";
		visit_pre_order<K,D>(root->left);
		visit_pre_order<K,D>(root->right);
	}
}

template <typename K, typename D> void visit_post_order(Node<K,D> * root)
{
	if (root != nullptr) {
		visit_post_order<K,D>(root->left);
		visit_post_order<K,D>(root->right);
		cout << root->key << ":" << root->data << " ";
	}
}

template <typename K, typename D> Node<K,D>* del_successor(Node<K,D>*  & root)
{
    if (root->left == nullptr) {
        Node<K,D>* p = root;
        root = root->right;
        return p;
    }
    else
        return del_successor<K,D>(root->left);
}

template <typename K, typename D> void bst_delete(Node<K,D>*  & root, K value_to_delete)
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
            Node<K,D>* p = root->left;
            delete root;
            root = p;
            return;
        }
        if (root->left == nullptr) {
            // no left subtree
            Node<K,D>* p = root->right;
            delete root;
            root = p;
            return;
        }
        // mid-node, find successor
        Node<K,D>* successor = del_successor<K,D>(root->right);
        root->key = successor->key;
        root->data = successor->data;
        delete successor;
        return;

    }
    else {
        if (value_to_delete > root->key)
            bst_delete<K,D>(root->right, value_to_delete);
        else
            bst_delete<K,D>(root->left, value_to_delete);
    }
}



int main(int argc, char **argv)
{
	Node<int,string> * mybst = nullptr;
	
	bst_insert<int,string>(mybst, 10, "aaa");
	bst_insert<int,string>(mybst, 5, "bbb");
	bst_insert<int,string>(mybst, 2, "ccc");
	bst_insert<int,string>(mybst, 30, "ddd");
	bst_insert<int,string>(mybst, 20, "eee");
	bst_insert<int,string>(mybst, 15, "fff");
	bst_insert<int,string>(mybst, 18, "ggg");
	bst_insert<int,string>(mybst, 40, "hhh");
	bst_insert<int,string>(mybst, 35, "iii");
	bst_insert<int,string>(mybst, 1, "jjj");
	bst_insert<int,string>(mybst, 3, "kkk");
	bst_insert<int,string>(mybst, 37, "lll");
	bst_insert<int,string>(mybst, 11, "mmm");
	bst_insert<int,string>(mybst, 22, "nnn");
	
	visit_in_order<int,string>(mybst); cout << endl;
	//visit_pre_order(mybst); cout << endl;
	//visit_post_order(mybst); cout << endl;
	
	cout << "Find 5: " << (int)bst_find<int,string>(mybst, 5) << endl;
	cout << "Find 7: " << (int)bst_find<int,string>(mybst, 7) << endl;
	cout << "Find 10: " << (int)bst_find<int,string>(mybst, 10) << endl;
	
	bst_delete<int,string>(mybst, 35);
	bst_delete<int,string>(mybst, 22);
	bst_delete<int,string>(mybst, 10);
	visit_in_order<int,string>(mybst); cout << endl;
	
	return 0;
}

