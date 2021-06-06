int Solution::maxcoin(vector<int> &A) {
    vector<vector<int>>vals(A.size(), vector<int>(A.size()/2, 0));
    int x;
    for(int i = 0; i < A.size()/2; i++) {
        x = 1 + 2 * i;
        for(int j = 0; j + x< A.size(); j++) {
            if(i == 0) {
                vals[j][0] = max(A[j], A[j + 1]);
            }
            else {
                vals[j][i] = max(A[j] + min(vals[j + 1][i - 1], vals[j + 2][i - 1]),
                                A[j + x] + min(vals[j][i - 1], vals[j + 1][i - 1]));
            }
        }
    }
    return vals[0][A.size()/2 - 1];
}
//maxmin