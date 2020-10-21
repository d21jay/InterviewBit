int Solution::solve(vector<int> &A) {
    int mmax, mmin;
    if(A.size() < 1) return 0;
    mmax = A[0];
    mmin = A[0];
    for(int i = 0; i < A.size(); i++) {
        if(A[i] < mmin) mmin = A[i];
        else if(A[i] > mmax) mmax = A[i];
    }
    return mmax + mmin;
}