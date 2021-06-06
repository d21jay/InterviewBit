int Solution::solve(string A) {
    int ans = 0;
    int mod = 10003;
    for(int i = 0; i < A.size(); i++) {
        switch((char)tolower(A[i])){
            case 'a': case 'e': case 'i': case 'o': case 'u':
                ans = (ans + (A.size() - i))%mod;
            break;
        }
    }
    return ans;
}