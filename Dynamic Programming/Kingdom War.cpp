int Solution::solve(vector<vector<int> > &A) {
    if(A.size() == 0 || A[0].size() == 0) return 0;
    int table[A[0].size()][2];
    int col = 1;
    int pcol = 0;
    table[A[0].size() - 1][0] = A[A.size() - 1][A[0].size() - 1];
    int ans = table[A[0].size() - 1][0];
    for(int i = A[0].size() - 2; i >= 0; i--) {
        table[i][0] = A[A.size() - 1][i] + table[i + 1][0];
        ans = max(ans, table[i][0]);
    }
    for(int i = A.size() - 2; i >= 0; i--) {
        table[A[0].size() - 1][col] = table[A[0].size() - 1][pcol] + A[i][A[0].size() - 1];
        ans = max(ans, table[A[0].size() - 1][col]);
        for(int j = A[0].size() - 2; j >= 0; j--) {
            table[j][col] = table[j + 1][col] + table[j][pcol] - table[j + 1][pcol] + A[i][j];
            ans = max(ans, table[j][col]);
        }
        col ^= 1;
        pcol ^= 1;
    }
    return ans;
}