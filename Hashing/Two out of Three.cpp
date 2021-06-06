vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    //100000 hence not hashing;
    vector<bool> a(100000, false);
    vector<bool> b(100000, false);
    vector<bool> c(100000, false);
    for(int i = 0; i < A.size(); i++) {
        a[A[i] - 1] = true;
    }
    for(int i = 0; i < B.size(); i++) {
        b[B[i] - 1] = true;
    }
    for(int i = 0; i < C.size(); i++) {
        c[C[i] - 1] = true;
    }
    vector<int> ans;
    int x;
    for(int i = 0; i < 100000; i++) {
        x = 0;
        if(a[i]) x++;
        if(b[i]) x++;
        if(c[i]) x++;
        if(x > 1) ans.push_back(i + 1);
    }
    return ans;
}