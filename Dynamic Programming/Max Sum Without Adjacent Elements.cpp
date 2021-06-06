int Solution::adjacent(vector<vector<int> > &A) {
    if(A.size() < 1 || A[0].size() < 1) return 0;
    if(A[0].size() == 1) return max(A[0][0], A[1][0]);
    int dp[A[0].size()][2] = {max(A[0][0], A[1][0])};
    int ans = dp[0][0];
    int con;
    dp[1][0] = max(A[0][1], A[1][1]);
    dp[1][1] = dp[0][0];
    //numbers are given to be positive.
    for(int i = 2; i < A[0].size(); i++) {
        con = max(dp[i - 2][0], dp[i - 2][1]);
        dp[i][0] = max(con + A[0][i], con + A[1][i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
    }
    return max(dp[A[0].size() - 1][0], dp[A[0].size() - 1][1]);
}