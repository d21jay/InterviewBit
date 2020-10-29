vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> sol(A, vector<int>(A, 0));
    int tar = A*A;
    int i, j, di, dj;
    bool c = false;
    i = 0;
    j = 0;
    di = 1;
    dj = 1;
    for(int k = 1; k <= tar; k++) {
        sol[i][j] = k;
        if(c) {
            if(i + di == A || i + di == -1 || sol[i + di][j] != 0) {
                di *= -1;
                c = false;
                j += dj;
            }
            else i +=di;
        }
        else {
            if(j + dj == A || j + dj == -1 || sol[i][j + dj] != 0) {
                dj *= -1;
                c = true;
                i += di;
            }
            else j +=dj;
        }
    }
    return sol;
}