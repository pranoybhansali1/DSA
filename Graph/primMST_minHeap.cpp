// adjacency list implementation

#include<bits/stdc++.h>
using namespace std;

int main(){
	int V=5,E=6;
	vector<pair<int,int> > adj[V]; 

	adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});
	
    int parent[V] = {-1};
    bool mSet[V] = {false};
    int key[V];
    fill(key, key+V, INT_MAX);
    int mstWt = 0;
    key[0] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    for(int count=0; count<V; count++) {
        int u = pq.top().second;
        pq.pop();
        mSet[u] = true;
        mstWt += key[u];
        
        for(auto it: adj[u]) {
            int v = it.first;
            int wt = it.second;
            if(!mSet[v] && key[v] > wt) {
                    key[v] = wt;
                    parent[v] = u;
                    pq.push({key[v], v});
            }
        }
    }
    cout<<"mstWt = "<<mstWt;
}
