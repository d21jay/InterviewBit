vector<int> Solution::findPerm(const string A, int B) {
    int lb = 1;
    int k = 1;
    vector<int> C;
    C.push_back(k);
    for(int i = 0; i < B - 1; i++) {
        if(A[i] == 'I') {
            k++;
            C.push_back(k);
        }
        else if(A[i] == 'D') {
            k--;
            C.push_back(k);
            if(k < lb) lb = k;
        }
    }
    k = 1 - lb;
    for(int i = 0; i < B; i++) C[i] += k;
    return C;
}