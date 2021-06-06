int Solution::cntPermBST(int A, int B) {
    int mod = 1000000007;
    vector<vector<int>> ans(B + 1, vector<int>(A + 1));
    vector<vector<int>> sum(B + 1, vector<int>(A + 1));
    vector<vector<int>> comb(A + 1, vector<int>(A + 1));
    //comb is nCk i.e n chose k;
    comb[0][0] = 1;
    for(int i = 1; i <= A; i++) {
        comb[i][0] = 1;
        for(int j = 1; j < A; j++) comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j])%mod;
        comb[i][i] = 1;
    }
    ans[0][0] = 1;
    ans[0][1] = 1;
    sum[0][0] = 1;
    sum[0][1] = 1;
    long long int x;
    long long int y;
    long long int z1, z2;
    for(int i = 1; i <= B; i++) {
        for(int j = 0; j <= A; j++) sum[i][j] = sum[i - 1][j];
        for(int j = i + 1; j <= A; j++) {
            x = 0;
            for(int k = 0; k < j; k++) {
                y = 0;
                z1 = ans[i - 1][k];
                z2 = ans[i - 1][j - k - 1];
                y = (y + (z1 * sum[i - 1][j - k - 1])%mod)%mod;
                y = (y + ((sum[i - 1][k] - z1) * z2)%mod)%mod;
                if(y < 0) y += mod;
                //we got number of BSTS. this step is req to get number of permutations:
                y = (y*comb[j - 1][k])%mod; // simce we need permutations of j - 1 nodes.
                x = (x + y)%mod;
            }
            ans[i][j] = x;
            sum[i][j] = (sum[i][j] + x)%mod;
        }
    }
    return ans[B][A];
}