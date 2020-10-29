int Solution::maxArr(vector<int> &A) {
    if(A.size() < 2) return 0;
    int amax, amin, dmax, dmin;
    amax = A[0];
    amin = A[0];
    dmax = A[0];
    dmin = A[0];
    for(int i = 1; i < A.size(); i++) {
        amax = max(amax, A[i] + i);
        amin = min(amin, A[i] + i);
        dmax = max(dmax, A[i] - i);
        dmin = min(dmin, A[i] - i);
    }
    return max(amax - amin, dmax - dmin);
}