int Solution::numDistinct(string A, string B) {
    if(A.size() < B.size()) return 0;
    int table[A.size() + 1][2];
    for(int i = 0; i <= A.size(); i++) {
        table[i][0] = 1;
    }
    int col = 1;
    int pcol = 0;
    for(int i = 0; i < B.size(); i++) {
        table[0][col] = 0;
        for(int j = 0; j < A.size(); j++) {
            if(j < i) table[j + 1][col] = 0;
            else {
                if(B[i] == A[j]) table[j + 1][col] = table[j][col] + table[j][pcol];
                else table[j + 1][col] = table[j][col];
            }
        }
        col ^= 1;
        pcol ^= 1;
    }
    return table[A.size()][pcol];
}