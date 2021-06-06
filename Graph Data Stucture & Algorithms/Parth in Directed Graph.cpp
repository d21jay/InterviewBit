int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj;
    vector<bool> vis(A, false);
    for(int i = 0; i < A; i++) adj.push_back({});
    for(int i = 0; i < B.size(); i++) {
        adj[B[i][0] - 1].push_back(B[i][1] - 1);
    }
    queue<int> q;
    q.push(0);
    int x;
    vis[0] = true;
    while(!q.empty()) {
        x = q.front();
        if(x == A - 1) return 1;
        q.pop();
        for(int i = 0; i < adj[x].size(); i++) {
            if(!vis[adj[x][i]]) {
                vis[adj[x][i]] = true;
                q.push(adj[x][i]);
            }
        }
    }
    return 0;
}