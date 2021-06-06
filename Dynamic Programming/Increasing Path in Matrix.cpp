int Solution::solve(vector<vector<int> > &A) {
    if(A.size() == 0) return -1;
    if(A[0].size() == 0) return -1;
    vector<vector<bool>> mark(A.size(), vector<bool>(A[0].size(), false));
    queue<pair<int, int>> q;
    int r = 0, c = 0;
    q.push({0, 0});
    mark[0][0] = true;
    while(!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        if(r + 1 < A.size() && A[r + 1][c] >= A[r][c] && !mark[r + 1][c]) {
            q.push({r + 1, c});
            mark[r + 1][c] = true;
        }
        if(c + 1 < A[0].size() && A[r][c + 1] >= A[r][c] && !mark[r][c + 1]) {
            q.push({r, c + 1});
            mark[r][c + 1] = true;
        }
    }
    if(r == A.size() - 1 && c == A[0].size() - 1) return r + c + 1;
    else return -1;
    //wrong qn statement. hence, soln to that.
}