int Solution::isInterleave(string A, string B, string C) {
    if(B.size() < A.size()) swap(A,B);
    bool table[A.size() + 1][2] = {false};
    table[0][0] = true;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == C[i]) table[i + 1][0] = true;
        else break;
    }
    int col = 1;
    int pcol = 0;
    for(int i = 0; i < B.size(); i++) {
            if(B[i] == C[i]) table[0][col] = table[0][pcol];
        for(int j = 0; j < A.size(); j++) {
            table[j + 1][col] = false;
            if(B[i] == C[i + j + 1]) {
                if(table[j + 1][pcol]) table[j + 1][col] = true;
            }
            if(A[j] == C[i + j + 1]) {
                if(table[j][col]) table[j + 1][col] = true;
            }
        }
        col ^= 1;
        pcol ^= 1;
    }
    if(table[A.size()][pcol]) return 1;
    else return 0;
}