vector<int> Solution::plusOne(vector<int> &A) {
    if(A.size() == 0) return {1};
    A[A.size() - 1]++;
    int x = A[A.size() - 1] / 10;
    A[A.size() - 1] %= 10;
    for(int i = A.size() - 2; i >= 0; i--) {
        if(x == 0) break;
        A[i]++;
        x = A[i] / 10;
        A[i] %= 10;
    }
    vector<int> B;
    if(x == 1){ 
        B.push_back(1);
        B.push_back(0);
    }
    int i = 0;
    while(A[i] == 0 && i < A.size()) i++;
    if(i == A.size()) i = 1;
    for(i; i < A.size(); i++) {
        B.push_back(A[i]);
    }
    return B;
}