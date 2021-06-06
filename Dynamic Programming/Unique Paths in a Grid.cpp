int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    if(A.size() == 0 || A[0].size() == 0) return 0;
    int table[A[0].size()][2] = {0};
    int col = 1;
    int pcol = 0;
    if(A[0][0] == 0) table[0][0] = 1;
    else return 0;
    for(int i = 1; i < A[0].size(); i++) {
        if(A[0][i] == 1) break;
        else table[i][0] = 1;
    }
    for(int i = 1; i < A.size(); i++) {
        if(A[i][0] == 0) table[0][col] = table[0][pcol];
        else table[0][col] = 0;
        for(int j = 1; j < A[0].size(); j++) {
            if(A[i][j] == 1) table[j][col] = 0;
            else table[j][col] = table[j - 1][col] + table[j][pcol];
        }
        col ^= 1;
        pcol ^= 1;
    }
    return table[A[0].size() - 1][pcol];
}