int Solution::solve(vector<vector<int> > &A) {
    if(A.size() == 0) return 0;
    int table[A.size()][2];
    int col = 1;
    int pcol = 0;
    table[0][0] = A[0][0];
    for(int i = 1; i < A.size(); i++) {
        table[0][col] = table[0][pcol] + A[i][0];
        for(int j = 1; j < i; j++) {
            table[j][col] = max(table[j - 1][pcol], table[j][pcol]) + A[i][j];
        }
        table[i][col] = table[i - 1][pcol] + A[i][i];
        col ^= 1;
        pcol ^= 1;
    }
    int ans = table[0][pcol];
    for(int i = 1; i < A.size(); i++) ans = max(ans, table[i][pcol]);
    return ans;
}