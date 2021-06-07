int Solution::solve(int A, vector<vector<int> > &B) {
    //bipartite problem. detect odd length cycle.
    //if(A < 2) return 0; not tested here.
    vector<int> mark(A);
    vector<vector<int>> edges(A, vector<int>());
    for(int i = 0; i < B.size(); i++) {
        edges[B[i][0] - 1].push_back(B[i][1] - 1);
        edges[B[i][1] - 1].push_back(B[i][0] - 1);
    }
    queue<int> q;
    int x, y, d;
    for(int j = 0; j < A; j++){
        if(mark[j] != 0) continue;
        q.push(j);
        mark[j] = 1;
        while(!q.empty()) {
            x = q.front();
            d = mark[x];
            q.pop();
            for(int i = 0; i < edges[x].size(); i++) {
                y = edges[x][i];
                if(mark[y] == mark[x]) return 0;
                if(mark[y] == 0) {
                    mark[y] = d + 1;
                    q.push(y);
                }
            }
        }
    }
    return 1;
}//don't forget connected components.