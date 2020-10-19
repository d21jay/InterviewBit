vector<int> Solution::solve(vector<int> &A) {
    vector<int> B;
    int cmax;
    if(A.size() > 0) {
        cmax = A[A.size()-1];
        B.push_back(cmax);
        for(int i = A.size() - 2; i >= 0; i--){
            if(A[i] > cmax) {
                cmax = A[i];
                B.push_back(cmax);
            }
        }
        reverse(B.begin(), B.end());
    }
    return B;
}