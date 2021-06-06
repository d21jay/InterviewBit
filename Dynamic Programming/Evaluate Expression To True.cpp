int Solution::cnttrue(string A) {
    int n = A.size()/2;
    int mod = 1003;
    vector<vector<int>> tWays(n + 1, vector<int>(n + 1));
    vector<vector<int>> fWays(n + 1, vector<int>(n + 1));
    vector<int> op(n);
    int atc, afc, btc, bfc;
    int x, y;
    for(int i = 0; i < A.size(); i++) {
        if(i % 2 == 0) {
            if(A[i] == 'T') tWays[(i + 1)/2][0] = 1;
            else fWays[(i + 1)/2][0] = 1;
        }
        else {
            if(A[i] == '^') op[i/2] = 1;
            else if(A[i] == '&') op[i/2] = 2;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j + i <=n; j++) {
            x = 0;
            y = 0;
            for(int k = 0; k < i; k++) {
               atc = tWays[j][k];
               afc = fWays[j][k];
               btc = tWays[j + k + 1][i - k - 1];
               bfc = fWays[j + k + 1][i - k - 1];
               if(op[j + k] == 0) {
                   x = (x + (((atc*btc)%mod + (atc*bfc)%mod)%mod + (afc*btc)%mod)%mod)%mod;
                   y = (y + (afc*bfc)%mod)%mod;
               }
               else if(op[j + k] == 1) {
                   x = (x + ((atc*bfc)%mod + (afc*btc)%mod)%mod)%mod;
                   y = (y + ((atc*btc)%mod + (afc*bfc)%mod)%mod)%mod;
               }
               else {
                   x = (x + (atc*btc)%mod)%mod;
                   y = (y + (((afc*bfc)%mod + (atc*bfc)%mod)%mod + (afc*btc)%mod)%mod)%mod;
               }
            }
            tWays[j][i] = x;
            fWays[j][i] = y;
        }
    }
    return tWays[0][n];
}