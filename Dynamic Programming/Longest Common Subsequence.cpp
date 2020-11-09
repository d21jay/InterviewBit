int Solution::solve(string A, string B) {
    if(A.size() > B.size()) swap(A,B);
    int lcs[A.size()][2] = {0};
    //it will raise compiler bug for interviewBit if you declare lcs[2][A.size()];
    int col = 1;
    int pcol = 0;
    int ffound = false;
    for(int i = 0; i < A.size(); i++) {
        if(ffound) lcs[i][0] = 1;
        else{
            if(A[i] == B[0]) {
                lcs[i][0] = 1;
                ffound = true;
            }
        }
    }
    for(int i = 1; i < B.size(); i++) {
        if(A[0] == B[i]) lcs[0][col] = 1;
        else lcs[0][col] = lcs[0][pcol];
        for(int j = 1; j < A.size(); j++) {
            if(A[j] == B[i]) lcs[j][col] = lcs[j - 1][pcol] + 1;
            else lcs[j][col] = max(lcs[j - 1][col], lcs[j][pcol]);
        }
        col ^= 1;
        pcol ^= 1;
    }
    return lcs[A.size() - 1][pcol];
}
//O(A.size() * B.size()) time and O( MIN(A.size(), B.size())) space.