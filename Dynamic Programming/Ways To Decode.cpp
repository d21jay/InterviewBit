int Solution::numDecodings(string A) {
    int mod = 1000000007;
    if(A.size() < 1) return 1;
    if(A[0] == '0') return 0;
    int ways[A.size() + 1] = {1, 1};
    for(int i = 1; i < A.size(); i++) {
        //input can be wrong too.
        if(A[i] == '0') {
            if(A[i - 1] != '1' && A[i - 1] != '2') return 0;
            ways[i + 1] = ways[i];
        }
        else if(A[i - 1] == '1') {
            if(i < A.size() - 2 && A[i + 1] == '0') ways[i + 1] = ways[i];
            else ways[i + 1] = (ways[i] + ways[i - 1]) % mod;
        }
        else if(A[i - 1] == '2') {
            if(i < A.size() - 2 && A[i + 1] == '0') ways[i + 1] = ways[i];
            else if(A[i] - '0' > 6) ways[i + 1] = ways[i];
            else ways[i + 1] = (ways[i] + ways[i - 1]) % mod;
        }
        else ways[i + 1] = ways[i];
    }
    return ways[A.size()];
}