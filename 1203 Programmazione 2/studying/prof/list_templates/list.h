/*
 * list.h
 */

#ifndef __LIST_H
#define __LIST_H

#include <iostream>
#include <string>

using namespace std; 

template <typename T> class List {
	T elem;
public:
	List() : next(nullptr) { };
	List(T e) : elem(e),next(nullptr) { };
	T get() { return elem; };
	virtual void insert(T data) {
		List<T> * nuovo_nodo = new List<T>(data);
		nuovo_nodo->next = this->next;
		this->next = nuovo_nodo;
	};
	void delete_first() {
		List<T> * first = this->next;	
		List<T> * new_first = first->next;
		delete first;
		this->next = new_first;
	};
	void delete_element(T data) {
		List<T> * current = this->next;
		List<T> * prev = this;	
		while (current != nullptr) {
			if (current->get() == data) {
				// dato trovato
				prev->next = current->next;
				delete current;
				return;
			}
			current = current->next;
			prev = prev->next;
		}
	};	
	
	void show(ostream & output = cout) {
		List<T> * p = this->next;
		while (p != nullptr) {
			output << p->get() << endl;		
			p = p->next;
		}
	};

	bool exist(T data) {
		List<T> * p = this->next;	
		while (p != nullptr) {
			if (p->get() == data)
				return true;
			p = p->next;
		}
		return false;
	};

	T * find(T data) {
		List<T> * p = this->next;	
		while (p != nullptr) {
			if (p->get() == data)
				return &p->elem;
			p = p->next;
		}
		return nullptr;
	};

	List<T> * next;
};

template <typename T> class OrderedList : public List<T> {
public:
	void insert(T data) {
		List<T> * new_node = new List<T>(data);
		List<T> * current = this->next;
		List<T> * prev = this;	
		while (current != nullptr && current->get() < data) {
			current = current->next;
			prev = prev->next;
		}
		prev->next = new_node;
		new_node->next = current;
	};
};

#endif

