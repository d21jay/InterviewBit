vector<int> Solution::subUnsort(vector<int> &A) {
    if(A.size() < 2) return {-1};
    vector<int> ans;
    int l, r, mmin, mmax;
    l = 0;
    r = A.size() - 1;
    for(int i = 0; i < A.size() - 1; i++) {
        if(A[i] <= A[i + 1]) l = i + 1;
        else break;
    }
    if(l == A.size() - 1) return {-1};
    for(int j = A.size() - 1; j > 0; j--) {
        if(A[j] >= A[j - 1]) r = j - 1;
        else break;
    }
    mmin = A[l];
    mmax = A[l];
    for(int i = l + 1; i <= r; i++) {
        mmin = min(mmin, A[i]);
        mmax = max(mmax, A[i]);
    }
    //since it is already taking O(n) no need for 2 binary searches.
    //can do for fun.
    cout<<l<<r;
    for(int i = 0; i <= l; i++) {
        if(A[i] > mmin) {
            ans.push_back(i);
            break;
        }
    }
    for(int i = A.size(); i >= r; i--) {
        if(A[i] < mmax) {
            ans.push_back(i);
            break;
        }
    }
    return ans;
}
//O(n) time O(1) space solution