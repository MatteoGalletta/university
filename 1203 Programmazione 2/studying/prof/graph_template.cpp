/*
 * graph.cpp
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

template <typename T>
class Graph {
	map<T, vector<T>> edges;
public:
	Graph() { };
	void add_node(T _node_id);
	void add_link(T _snode, T _dnode); 
	void show_links();
};

template <typename T>
void Graph<T>::add_node(T _node_id)
{
	vector<T> v;
	edges[_node_id] = v;
}

template <typename T>
void Graph<T>::add_link(T _snode, T _dnode)
{
	edges[_snode].push_back(_dnode);
	edges[_dnode].push_back(_snode);
}

template <typename T>
void Graph<T>::show_links()
{
	for (typename map<T, vector<T>>::iterator it = edges.begin(); it != edges.end(); it++) {
		T snode = it->first;
		vector<T> & links = it->second;
		cout << "Node : " << snode << "--> "; 
		for (typename vector<T>::iterator link_it = links.begin(); link_it != links.end(); link_it++) {
			cout << (*link_it) << " ";
		}
		cout << endl;
	}
}

int main(int argc, char ** argv)
{
	Graph<string> g;
	
	g.add_node("1");
	g.add_node("2");
	g.add_node("3");
	g.add_node("4");
	g.add_node("5");
	g.add_node("6");
	
	g.add_link("1","2");
	g.add_link("1","3");
	g.add_link("1","4");
	g.add_link("2","6");
	g.add_link("4","5");
	g.add_link("3","5");
	g.add_link("3","6");
	g.add_link("6","5");
	
	g.show_links();
	
	return 0;
}

