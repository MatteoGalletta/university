/*
 * graph.cpp
 */
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Graph {
	int ** edges;
	int n_nodes;
	map<int, bool> visited;
	void _recursive_depth_search(int _snode, int _dnode);
public:
	Graph(int n);
	void add_link(int _snode, int _dnode); 
	void depth_search(int _snode, int _dnode = -1);
	void breath_search(int _snode);
	void show_links();
	bool linked(int _snode, int _dnode);
};

Graph::Graph(int n)
{
	n_nodes = n;
	edges = new int*[n_nodes];
	for (int i = 0; i < n_nodes;i++) {
		edges[i] = new int[n_nodes];
		for (int j = 0; j < n_nodes;j++)
			edges[i][j] = 0;
	}
}

// node numbering starts from 1
void Graph::add_link(int _snode, int _dnode)
{
	edges[_snode - 1][_dnode - 1] = 1;
	edges[_dnode - 1][_snode - 1] = 1;
}

bool Graph::linked(int _snode, int _dnode)
{
	return edges[_snode - 1][_dnode - 1] == 1;
}

void Graph::show_links()
{
	for (int row = 0; row < n_nodes; row ++) {
		cout << "Node : " << (row + 1) << "--> "; 
		for (int col = 0; col < n_nodes; col ++) {
			if (edges[row][col] == 1)
				cout << (col + 1) << " ";
		}
		cout << endl;
	}
}


void Graph::depth_search(int _snode, int _dnode)
{
	for (int i = 1; i <= n_nodes;i++) {
		visited[i] = false;
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
		visited[_snode] = true;
		cout << _snode << " ";
		for (int next = 1; next <= n_nodes; next ++ ) {
			if (linked(_snode, next))
				_recursive_depth_search(next, _dnode);
		}
	}
	else {
		cout << "(" << _snode << ")" << endl;
	}
}


void Graph::breath_search(int _snode)
{
	for (int i = 1; i <= n_nodes;i++) {
		visited[i] = false;
	}
	
	queue<int> node_queue;
	node_queue.push(_snode);
	while (!node_queue.empty()) {
		int n = node_queue.front();
		node_queue.pop();
		if (!visited[n]) {
			cout << n << " ";
			visited[n] = true;
			for (int next = 1; next <= n_nodes; next ++ ) {
				if (linked(_snode, next))
					node_queue.push(next);
			}
		}
	}
	cout << endl;
}


int main(int argc, char ** argv)
{
	Graph g(6);
	
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

