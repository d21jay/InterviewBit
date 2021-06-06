int Solution::solve(string A) {
    int ccount = 0;
    int vcount = 0;
    int mod = 1000000007;
    int ans = 0;
    char c;
    for(int i = 0; i < A.size(); i++) {
        c = A[i];
        switch(c) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                ans = (ans + ccount)%mod;
                vcount++;
            break;
            default:
                ans = (ans + vcount)%mod;
                ccount++;
        }
    }
    return ans;
}