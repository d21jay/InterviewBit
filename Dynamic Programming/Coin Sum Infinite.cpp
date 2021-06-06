int Solution::coinchange2(vector<int> &A, int B) {
    vector<int>poss(B + 1, 0);
    poss[0] = 1;
    int x;
    int mod = 1000007;
    for(int i = 0; i < A.size(); i++) {
        x = A[i];
        for(int j = 0; j + x <= B; j++ ) {
            if(poss[j]) poss[j + x] = (poss[j + x] + poss[j]) % mod;
        }
    }
    return poss[B];
}