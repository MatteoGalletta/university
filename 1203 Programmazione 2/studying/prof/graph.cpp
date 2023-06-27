/*
 * graph.cpp
 */
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Graph {
	map<int, vector<int>> edges;
	map<int, bool> visited;
	void _recursive_depth_search(int _snode, int _dnode);
public:
	Graph() { };
	void add_node(int _node_id);
	void add_link(int _snode, int _dnode); 
	void depth_search(int _snode, int _dnode = -1);
	void breath_search(int _snode);
	void show_links();
};

void Graph::add_node(int _node_id)
{
	vector<int> v;
	edges[_node_id] = v;
}

void Graph::add_link(int _snode, int _dnode)
{
	edges[_snode].push_back(_dnode);
	edges[_dnode].push_back(_snode);
}

void Graph::show_links()
{
	for (map<int, vector<int>>::iterator it = edges.begin(); it != edges.end(); it++) {
		int snode = it->first;
		vector<int> & links = it->second;
		cout << "Node : " << snode << "--> "; 
		for (vector<int>::iterator link_it = links.begin(); link_it != links.end(); link_it++) {
			cout << (*link_it) << " ";
		}
		cout << endl;
	}
}

void Graph::depth_search(int _snode, int _dnode)
{
	for (map<int, vector<int>>::iterator it = edges.begin(); it != edges.end(); it++) {
		int snode = it->first;
		visited[snode] = false;
	}
	_recursive_depth_search(_snode, _dnode);
}

void Graph::_recursive_depth_search(int _snode, int _dnode)
{
	if (_snode == _dnode) {
		cout << _snode << endl;
		return;
	}
	if (!visited[_snode]) {
		vector<int> & links = edges[_snode];
		visited[_snode] = true;
		cout << _snode << " ";
		for (vector<int>::iterator link_it = links.begin(); link_it != links.end(); link_it++) {
			_recursive_depth_search((*link_it), _dnode);
		}
	}
	else {
		cout << "(" << _snode << ")" << endl;
	}
}

void Graph::breath_search(int _snode)
{
	for (map<int, vector<int>>::iterator it = edges.begin(); it != edges.end(); it++) {
		int snode = it->first;
		visited[snode] = false;
	}
	
	queue<int> node_queue;
	node_queue.push(_snode);
	while (!node_queue.empty()) {
		int n = node_queue.front();
		node_queue.pop();
		if (!visited[n]) {
			cout << n << " ";
			visited[n] = true;
			vector<int> & links = edges[n];
			for (vector<int>::iterator link_it = links.begin(); link_it != links.end(); link_it++) {
				node_queue.push((*link_it));
			}
		}
	}
	cout << endl;
}


int main(int argc, char ** argv)
{
	Graph g;
	
	g.add_node(1);
	g.add_node(2);
	g.add_node(3);
	g.add_node(4);
	g.add_node(5);
	g.add_node(6);
	
	g.add_link(1,2);
	g.add_link(1,3);
	g.add_link(1,4);
	g.add_link(2,6);
	g.add_link(4,5);
	g.add_link(3,5);
	g.add_link(3,6);
	g.add_link(6,5);
	
	g.show_links();
	
	//g.depth_search(1,6);
	g.depth_search(1);
	
	g.breath_search(1);
	
	return 0;	
}

