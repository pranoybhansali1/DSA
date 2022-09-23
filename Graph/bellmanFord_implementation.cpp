// Question Link: https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
// Distance from the Source (Bellman-Ford Algorithm)

vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> dist(V);
        fill(dist.begin(), dist.end(), 100000000);
        dist[S] = 0;
        for(int count=0; count<V-1; count++) {
            for(int i=0; i<adj.size(); i++) {
                int u = adj[i][0], v = adj[i][1], w = adj[i][2];
                if(dist[v] > dist[u] + w)
                    dist[v] = dist[u] + w;
                }
            }
        return dist;
    }
