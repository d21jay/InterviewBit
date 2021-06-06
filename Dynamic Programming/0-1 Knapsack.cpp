int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    if(A.size() == 0) return 0;
    int table[C + 1][2] = {0};
    int col = 1;
    int pcol = 0;
    for(int i = 0; i <= C; i++) {
        if(B[0] <= i) table[i][0] = A[0];
    }
    for(int i = 1; i < A.size(); i++) {
        for(int j = 0; j <= C; j++) {
            if(j - B[i] >= 0)
                table[j][col] = max(table[j][pcol], table[j - B[i]][pcol] + A[i]);
            else table[j][col] = table[j][pcol];
        }
        col ^= 1;
        pcol ^= 1;
    }
    int ans = 0;
    for(int i = 0; i <= C; i++) ans = max(ans, table[i][pcol]);
    return ans;
}