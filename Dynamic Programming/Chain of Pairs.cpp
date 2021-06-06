int Solution::solve(vector<vector<int> > &A) {
    if(A.size() < 1) return 0;
    int ans = 1;
    int dp[A.size()] = {1};
    int cmax;
    for(int i = 1; i < A.size(); i++) {
        cmax = 0;
        for(int j = 0; j < i; j++) {
            if(A[i][0] > A[j][1]) cmax = max(cmax, dp[j]);
        }
        dp[i] = cmax + 1;
        ans = max(ans, dp[i]);
    }
    return ans;
}