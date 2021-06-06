int Solution::solve(int A, int B) {
    int mod = 1000000007;
    if(B == 0) return (int)(A == 0);
    vector<vector<int>> sum(A, vector<int>(B + 1, 0));
    for(int i = 1; i < 10; i++) {
        if(B >= i) sum[0][i] = 1;
    }
    for(int i = 1; i < A; i++) {
        for(int j = 0; j <= B; j++) {
            if(sum[i - 1][j] != 0){
                for(int k = 0; k < 10; k++) {
                    if(k + j <= B) sum[i][j + k] = (sum[i][j + k] + sum[i - 1][j])%mod;
                }
            }
        }
    }
    return sum[A - 1][B];
}