int Solution::solve(vector<vector<int> > &A, int B) {
    if(B == 0 || B > A.size()) return 0;
    int table[A.size() - B + 1][2] = {0};
    int col = 1;
    int pcol = 0;
    for(int i = 0; i < B; i ++) {
        for(int j = 0; j < B; j++) {
            table[0][0] += A[i][j];
        }
    }
    int mSum = table[0][0];
    for(int j = 1; j <= A.size() - B; j++) {
        table[j][0] = table[j - 1][0];
        for(int i = 0; i < B; i++) {
            table[j][0] += (A[i][j + B - 1] - A[i][j - 1]);
        }
        mSum = max(mSum, table[j][0]);
    }
    for(int k = 1; k <= A.size() - B; k++) {
        table[0][col] = table[0][pcol];
        for(int j = 0; j < B; j++) {
            table[0][col] += (A[k + B - 1][j] - A[k - 1][j]);
        }
        mSum = max(mSum, table[0][col]);
        for(int j = 1; j <= A.size() - B; j++) {
            table[j][col] = table[j - 1][col] + table[j][pcol] - table[j - 1][pcol]
                + A[k - 1][j - 1] - A[k - 1][j + B - 1] - A[k + B - 1][j-1] + A[k + B - 1][j + B - 1];
            mSum = max(mSum, table[j][col]);
        }
        col ^= 1;
        pcol ^= 1;
    }
    return mSum;
}
//O(n^2) time and O(n) space soln.
//alternate soln: O((n^2)*B) = O(n^3) time with O(1) space. 