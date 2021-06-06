int Solution::lis(const vector<int> &A) {
    int listSize[A.size()];
    int *a;
    int ans = 0;
    for(int i = 0;  i < A.size(); i++) {
        a = lower_bound(listSize, listSize + ans, A[i]);
        *a = A[i];
        ans = max(ans, (int)(a - listSize) + 1);
    }
    return ans;
}
//O(n log n)