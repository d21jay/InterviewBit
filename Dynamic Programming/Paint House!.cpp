int Solution::solve(vector<vector<int> > &A) {
    int xc0, c0, xc1, c1, c2;
    c0 = A[0][0];
    c1 = A[0][1];
    c2 = A[0][2];
    for(int i = 1; i < A.size(); i++){
        xc0 = A[i][0] + min(c1, c2);
        xc1 = A[i][1] + min(c0, c2);
        c2 = A[i][2] + min(c0, c1);
        c0 = xc0;
        c1 = xc1;
    }
    return min(c0, min(c1, c2));
}