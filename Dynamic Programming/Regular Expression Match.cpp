int Solution::isMatch(const string A, const string B) {
    bool table[B.size() + 1][2] = {true};
    //only index 0, 0 initialized true, rest false;
    for(int i = 0; i < B.size(); i++) {
        if(B[i] == '*') table[i + 1][0] = true;
        else break;
    }
    int col = 1;
    int pcol = 0;
    for(int i = 0; i < A.size(); i++) {
        table[0][col] = false;
        for(int j = 0; j < B.size(); j++) {
            if(B[j] == '*') table[j + 1][col] = table[j][col] || table[j + 1][pcol];
            else if(A[i] == B[j] || B[j] == '?') table[j + 1][col] = table[j][pcol];
            else table[j + 1][col] = false;
        }
        col ^= 1;
        pcol ^= 1;
    }
    if(table[B.size()][pcol]) return 1;
    else return 0;
}