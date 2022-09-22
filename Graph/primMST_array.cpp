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
    
    for(int count=0; count<V; count++) {
        int u = -1;
        // cout<<"u = -1\n";
        for(int i=0; i<V; i++) {
            if(!mSet[i] && (u == -1 || key[u] > key[i]))
                u = i;
        }
        // cout<<"\tu = "<<u<<"\n";
        mSet[u] = true;
        mstWt += key[u];
        // cout<<"jey[u] = "<<key[u]<<"\n";

        for(auto v: adj[u]) {
            if(!mSet[v.first]) {
                if(key[v.first] > v.second) {
                    key[v.first] = v.second;
                    parent[v.first] = u;
                }
            }
        }
    }
    cout<<"mstWt = "<<mstWt;
}
