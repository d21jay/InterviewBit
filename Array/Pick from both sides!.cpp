int Solution::solve(vector<int> &A, int B) {
    int ans = 0;
    int cSum = 0;
    for(int i = 0; i < B; i++) cSum += A[i];
    ans = cSum;
    for(int i = 0; i < B; i++) {
        cSum += (A[A.size() - i - 1] - A[B - i - 1]);
        ans = max(ans, cSum);
    }
    return ans;
}