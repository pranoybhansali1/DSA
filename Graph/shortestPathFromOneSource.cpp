#include<bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	int E;
	vector<pair<int, int>> *adj;
public:
	Graph(int V, int E) {
		this->V = V;
		this->E = E;
		this->adj = new vector<pair<int, int>>[V];
	}

	void addEdge(int u, int v, int wt) {
		adj[u].push_back({v, wt});
	}

	vector<int> topologicalSort() {
		int indegree[V] = {0};
		vector<int> topSort;
		for(int i=0; i<V; i++) {
			for(auto it: adj[i]) {
				indegree[it.first]++;
			}
		}
		queue<int> q;
		for(int i=0; i<V; i++)
			if(indegree[i] == 0)
				q.push(i);

		while(q.empty()==0) {
			int u = q.front();
			q.pop();
			topSort.push_back(u);
			for(auto it: adj[u]) {
				indegree[it.first]--;
				if(indegree[it.first] == 0)
					q.push(it.first);
			}
		}
		return topSort;
	}

	void findShortestPath(int s) {
		vector<int> topSort = topologicalSort();
		int dist[V] = {INT_MAX};
		dist[s] = 0;
		for(int u: topSort) {
			for(auto v: adj[u]) {
				if(dist[v.first] > (dist[u] + v.second))
					dist[v.first] = (dist[u] + v.second);
			}
		}
		for(int v: dist)
			cout<<v<<" ";
		cout<<"====end\n\n";
	}	
};

int main(int argc, char const *argv[])
{
	int V = 6;
	int E = 9;
	Graph G(V, E);

    G.addEdge(1, 3, 6);

    G.addEdge(1, 2, 2);

    G.addEdge(0, 1, 5);

    G.addEdge(0, 2, 3);

    G.addEdge(3, 4, -1);

    G.addEdge(2, 4, 4);

    G.addEdge(2, 5, 2);

    G.addEdge(2, 3, 7);

    G.addEdge(4, 5, -2);

    G.findShortestPath(0);
	return 0;
}
