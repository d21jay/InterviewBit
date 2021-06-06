int Solution::maxProduct(const vector<int> &A) {
    //assuming no overflow;
    if(A.size() == 0) return 0;
    int ans = A[0];
    vector<int> pos(A.size());
    vector<int> neg(A.size());
    if(A[0] > 0) pos[0] = A[0];
    else neg[0] = A[0];
    for(int i = 1; i < A.size(); i++) {
        if(A[i] > 0) {
            if(pos[i - 1] != 0) pos[i] = pos[i - 1]*A[i];
            else pos[i] = A[i];
            neg[i] = neg[i - 1]*A[i];
        }
        else {
            pos[i] = neg[i - 1]*A[i];
            if(pos[i - 1] != 0) neg[i] = pos[i - 1]*A[i];
            else neg[i] = A[i];
        }
        ans = max(ans, pos[i]);
    }
    return ans;
}