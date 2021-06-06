int Solution::arrange(string A, int B) {
    if(B < 1 || B > A.size()) return -1;
    int b = 0, w = 0;
    vector<int> bc, wc;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == 'W') w++;
        else b++;
        bc.push_back(b);
        wc.push_back(w);
    }
    vector<vector<int>> mat(B, vector<int>(A.size()));
    for(int i = 1; i < A.size(); i++) {
        mat[0][i] = bc[i]*wc[i];
    }
    for(int i = 1; i < B; i++) {
        for(int j = i + 1; j < A.size(); j++) {
            mat[i][j] = (bc[j] - bc[i - 1])*(wc[j] - wc[i - 1]);
            for(int k = i; k < j; k++) {
                mat[i][j] = min(mat[i][j], mat[i - 1][k] + (bc[j] - bc[k])*(wc[j] - wc[k]));
            }
        }
    }
    return mat[B - 1][A.size() - 1];
}