int Solution::solve(vector<vector<int> > &A, int B) {
    if(B == 0 || B > A.size()) return 0;
    int baseSum = 0;
    for(int i = 0; i < B; i ++) {
        for(int j = 0; j < B; j++) {
            baseSum += A[i][j];
        }
    }
    int cSum, mSum = baseSum;
    cSum = baseSum;
    for(int j = 1; j <= A.size() - B; j++) {
        for(int i = 0; i < B; i++) {
            cSum += (A[i][j + B - 1] - A[i][j - 1]);
        }
        mSum = max(mSum, cSum);
    }
    for(int k = 1; k <= A.size() - B; k++) {
        for(int j = 0; j < B; j++) {
            baseSum += (A[k + B - 1][j] - A[k - 1][j]);
        }
        mSum = max(mSum, baseSum);
        cSum = baseSum;
        for(int j = 1; j <= A.size() - B; j++) {
            for(int i = k; i < k + B; i++) {
                cSum += (A[i][j + B - 1] - A[i][j - 1]);
            }
            mSum = max(mSum, cSum);
        }
    }
    
    return mSum;
}