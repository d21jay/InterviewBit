int Solution::solve(vector<vector<int> > &A) {
    if(A.size() == 0 || A[0].size() == 0) return 0;
    int table[A[0].size()][2] = {0};
    int col = 1;
    int pcol = 0;
    int ans = 0;
    for(int i = 0; i < A[0].size(); i++) {
        if(A[0][i] == 1) {
            table[i][0] = 1;
            ans = 1;
        }
    }
    for(int i = 1; i < A.size(); i++) {
        if(A[i][0] == 1) {
            table[0][col] = 1;
            ans = max(ans, 1);
        }
        else table[0][col] = 0;
        for(int j = 1; j < A[0].size(); j++) {
            if(A[i][j] == 1) {
                table[j][col] = min(min(table[j][pcol], table[j - 1][pcol]), table[j - 1][col]) + 1;
                ans = max(ans, table[j][col]);
            }
            else table[j][col] = 0;
        }
        col ^= 1;
        pcol ^= 1;
    }
    return ans*ans;
}