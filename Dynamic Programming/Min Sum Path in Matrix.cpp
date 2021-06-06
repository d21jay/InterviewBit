int Solution::minPathSum(vector<vector<int> > &A) {
    if(A.size() == 0 || A[0].size() == 0) return 0;
    int table[A[0].size()][2];
    table[0][0] = A[0][0];
    int col = 1;
    int pcol = 0;
    for(int i = 1; i < A[0].size(); i++) {
        table[i][0] = table[i - 1][0] + A[0][i];
    }
    for(int i = 1; i < A.size(); i++) {
        table[0][col] = table[0][pcol] + A[i][0];
        for(int j = 1; j < A[0].size(); j++) {
            table[j][col] = min(table[j - 1][col], table[j][pcol]) + A[i][j];
        }
        col ^= 1;
        pcol ^= 1;
    }
    return table[A[0].size() - 1][pcol];
}