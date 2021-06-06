int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    if(A.size() == 0 || A[0].size() == 0) return 0;
    int mhp[A[0].size()][2];
    mhp[A.size() - 1][0] = max(1 - A[A.size() - 1][A[0].size() - 1], 1);
    for(int i = A.size() - 2; i >= 0; i--) {
        mhp[i][0] = max(mhp[i + 1][0] - A[A.size() - 1][i], 1);
    }
    int col = 1;
    int pcol = 0;
    for(int i = A.size() - 2; i >= 0; i--) {
        mhp[A[0].size() - 1][col] = max(mhp[A[0].size() - 1][pcol] - A[i][A[0].size() - 1], 1);
        for(int j = A.size() - 2; j >= 0; j--) {
            mhp[j][col] = max(min(mhp[j][pcol], mhp[j + 1][col]) - A[i][j], 1);
        }
        col ^= 1;
        pcol ^= 1;
    }
    return mhp[0][pcol];
}