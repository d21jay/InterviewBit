void BFSEngine(vector<string> &A, int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        A[i][j] = 'O';
        if(i + 1 < A.size() && A[i + 1][j] == 'X') q.push({i + 1, j});
        if(i > 0 && A[i - 1][j] == 'X') q.push({i - 1, j});
        if(j + 1 < A[0].size() && A[i][j + 1] == 'X') q.push({i, j + 1});
        if(j > 0 && A[i][j - 1] == 'X') q.push({i, j - 1}); 
    }
}
int Solution::black(vector<string> &A) {
    int ans = 0;
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            if(A[i][j] == 'X'){
                BFSEngine(A, i, j);
                ans++;
            }
        }
    }
    return ans;
}