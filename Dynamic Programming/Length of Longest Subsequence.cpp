int Solution::longestSubsequenceLength(const vector<int> &A) {
    int lis[A.size()];
    int lds[A.size()];
    int lisi[A.size()];
    int ldsi[A.size()];
    int a;
    int is = 0;
    int ds = 0;
    int ans = 0;
    for(int i = 0;  i < A.size(); i++) {
        a = lower_bound(lis, lis + is, A[i]) - lis;
        lis[a] = A[i];
        a++;
        lisi[i] = a;
        is = max(is, a);
    }
    for(int i = A.size() - 1; i >= 0; i--) {
        a = lower_bound(lds, lds + ds, A[i]) - lds;
        lds[a] = A[i];
        a++;
        ldsi[i] = a;
        ds = max(ds, a);
    }
    for(int i = 0; i < A.size(); i++) {
        ans = max(ans, lisi[i] + ldsi[i] - 1);
    }
    return ans;
}
//O(n log n)