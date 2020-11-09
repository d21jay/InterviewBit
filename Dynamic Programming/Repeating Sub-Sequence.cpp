int Solution::anytwo(string A) {
    //though dp is not required, lets do it.
    int table[A.size() + 1][2] = {0};
    int col = 1;
    int pcol = 0;
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A.size(); j++) {
            if(A[i] == A[j] && i != j) {
                table[j + 1][col] = table[j][pcol] + 1;
            }
            else {
                table[j + 1][col] = max(table[j][col], table[j + 1][pcol]);
            }
        }
        col ^= 1;
        pcol ^= 1;
    }
    
    if(table[A.size()][pcol] >= 2) return 1;
    else return 0;
}