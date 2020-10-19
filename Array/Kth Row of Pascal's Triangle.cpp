vector<int> Solution::getRow(int A) {
    A = A + 1;
    if(A == 1) return {1};
    if(A == 2) return {1, 1};
    vector<int> B(A, 1);
    vector<int> C(A, 1);
    int odd = 0;
    for(int i = 2; i < A; i++) {
        if(odd == 0){
            for(int j = 1; j < i; j++ )
                C[j] = B[j-1] + B[j];
        }
        else {
            for(int j = 1; j < i; j++ )
                B[j] = C[j-1] + C[j];
        }
        odd ^= 1;
    }
    if(odd == 1) return C;
    else return B;
}