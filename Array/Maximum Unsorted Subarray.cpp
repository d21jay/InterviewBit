vector<int> Solution::subUnsort(vector<int> &A) {
    vector<int> B(A);
    sort(B.begin(), B.end());
    int s, e;
    s = -1, e = -1;
    for(int i = 0; i <  A.size(); i++) {
        if(B[i] != A[i]) {
            if(s == -1) s = i;
            e = i;
        }
    }
    if(s == -1) return {-1};
    return {s, e};
}