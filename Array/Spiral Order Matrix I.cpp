vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int tar = A.size()*A[0].size();
    vector<int> sol(tar, 0);
    int i, j, di, dj, rlb, rhb, clb, chb;
    bool c = false;
    i = 0;
    j = 0;
    di = 1;
    dj = 1;
    rlb = -1;
    rhb = A[0].size();
    clb = 0;
    chb = A.size();
    for(int k = 0; k < tar; k++) {
        sol[k] = A[i][j];
        if(c) {
            if(i + di == clb || i + di == chb) {
                if(i + di == clb) clb++;
                else chb--;
                di *= -1;
                c = false;
                j += dj;
            }
            else i += di;
        }
        else {
            if(j + dj == rlb || j + dj == rhb) {
                if(j + dj == rlb) rlb++;
                else rhb--;
                dj *= -1;
                c = true;
                i += di;
            }
            else j +=dj;
        }
    }
    return sol;
}