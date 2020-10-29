vector<int> Solution::solve(vector<int> &A) {
    if(A.size() == 0) return {};
    int index = 0;
    int mmin = abs(A[0]);
    for(int i = 0; i < A.size(); i++) {
        if(abs(A[i]) < mmin) {
            mmin = abs(A[i]);
            index = i;
        }
    }
    vector<int> B;
    B.push_back(A[index]*A[index]);
    int l = index - 1;
    int r = index + 1;
    while(B.size() < A.size()) {
        if(l >= 0 && r < A.size()) {
            if(abs(A[l]) > A[r]) {
                B.push_back(A[r]*A[r]);
                r++;
            }
            else {
                B.push_back(A[l]*A[l]);
                l--;
            }
        }
        else if(l >= 0) {
            B.push_back(A[l]*A[l]);
            l--;
        }
        else{
            B.push_back(A[r]*A[r]);
            r++;
        }
    }
    return B;
}