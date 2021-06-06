int Solution::maxProfit(const vector<int> &A) {
    int ans = 0;
    if(A.size() == 0) return 0;
    int mtill = A[0];
    for(int i = 1; i < A.size(); i++) {
        ans = max(ans, A[i] - mtill);
        mtill = min(A[i], mtill);
    }
    return ans;
}