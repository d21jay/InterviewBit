int Solution::maxProfit(const vector<int> &A) {
    if(A.size() == 0) return 0;
    int ans = - 1 * A[0];
    for(int i = 0; i < A.size() - 1; i++) {
        if(A[i] > A[i + 1]) {
            ans += (A[i] - A[i + 1]);
        }
    }
    ans +=A[A.size() - 1];
    return ans;
}