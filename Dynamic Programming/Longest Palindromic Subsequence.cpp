int Solution::solve(string A) {
    int lcps[A.size()][2] = {0};
    bool ffound = false;
    for(int i = A.size(); i >= 0; i--) {
        if(ffound) lcps[i][0] = 1;
        else{
            if(A[i] == A[0]) {
                lcps[i][0] = 1;
                ffound = true;
            }
        }
    }
    int col = 1;
    int pcol = col^col;
    for(int i = 1; i < A.size(); i++) {
        if(A[i] == A[A.size() - 1]) lcps[A.size() - 1][col] = 1;
        else lcps[A.size() - 1][col] = lcps[A.size() - 1][pcol];
        for(int j = A.size() - 2; j >= 0; j--) {
            if(A[i] == A[j]) lcps[j][col] = 1 + lcps[j + 1][pcol];
            else lcps[j][col] = max(lcps[j + 1][col], lcps[j][pcol]);
        }
        col ^= 1;
        pcol ^= 1;
    }
    return lcps[0][pcol];
}