Ques link - https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
vector<string> paths;
void findPathUtil(vector<vector<int>> &m, vector<vector<int>> &vis, int n, int i, int j, string path) {
    if(i==n-1 && j==n-1) {
        paths.push_back(path);
        return;
    }

    if(i+1<n && !vis[i+1][j] && m[i+1][j]==1) {
        vis[i][j] = 1;
        findPathUtil(m, vis, n, i+1, j, path+"D");
        vis[i][j] = 0;
    }

    if(j-1>=0 && !vis[i][j-1] && m[i][j-1]==1) {
        vis[i][j] = 1;
        findPathUtil(m, vis, n, i, j-1, path+"L");
        vis[i][j] = 0;
    }

    if(j+1<n && !vis[i][j+1] && m[i][j+1]==1) {
        vis[i][j] = 1;
        findPathUtil(m, vis, n, i, j+1, path+"R");
        vis[i][j] = 0;
    }

    if(i-1>=0 && !vis[i-1][j] && m[i-1][j]==1) {
        vis[i][j] = 1;
        findPathUtil(m, vis, n, i-1, j, path+"U");
        vis[i][j] = 0;
    }
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    if(m[0][0] == 0)
        return paths;
    vector<vector<int>> vis(n, vector<int>(n,0));
    findPathUtil(m, vis, n, 0, 0, "");
    return paths;
}
