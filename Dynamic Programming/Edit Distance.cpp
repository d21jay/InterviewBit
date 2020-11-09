void memoize(vector<vector<int>> &cost, string &A, string &B, int i, int j) {
    if(i == B.size()) {
        cost[i][j] = A.size() - j;
        return;
    }
    if(j == A.size()) {
        cost[i][j] = B.size() - i;
        return;
    }
    if(cost[i + 1][j + 1] == -1) memoize(cost, A, B, i + 1, j + 1);
    if(A[j] == B[i]) {
        cost[i][j] = cost[i + 1][j + 1];
    }
    else {
        if(cost[i + 1][j] == -1) memoize(cost, A, B, i + 1, j);
        if(cost[i][j + 1] == -1) memoize(cost, A, B, i, j + 1);
        cost[i][j] = min(cost[i + 1][j + 1], min(cost[i + 1][j], cost[i][j + 1])) + 1;
    }
    return;
}

int Solution::minDistance(string A, string B) {
    vector<vector<int>> cost(B.size() + 1, vector<int>(A.size() + 1, -1)); 
    memoize(cost, A, B, 0, 0);
    return cost[0][0];
}