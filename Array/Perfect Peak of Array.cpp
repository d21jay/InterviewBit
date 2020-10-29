int Solution::perfectPeak(vector<int> &A) {
    vector<int> gs(A.size(), INT_MIN);
    vector<int> ls(A.size(), INT_MAX);
    for(int i = 1; i < A.size(); i++) {
        gs[i] = max(gs[i - 1], A[i - 1]);
    }
    for(int i = A.size() - 2; i >= 0; i--) {
        ls[i] = min(ls[i + 1], A[i + 1]);
    }
    for(int i = 1; i < A.size() - 1; i++) {
        if(gs[i] < A[i] && ls[i] > A[i]) return 1;
    }
    return 0;
}