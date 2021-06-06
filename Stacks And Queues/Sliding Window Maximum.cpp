vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    if(A.size() == 0) return {};
    B = min(B, (int)A.size());
    vector<int>dq(A.size(), 0);
    int l = 0, r = 0;
    vector<int> ans;
    for(int i = 0; i < A.size(); i++) {
        while(dq[l] <= i - B && l < r) l++;
        while(r>l && A[i] > A[dq[r - 1]]) r--;
        dq[r] = i;
        r++;
        if(i >= B - 1) ans.push_back(A[dq[l]]);
    }
    return ans;
}