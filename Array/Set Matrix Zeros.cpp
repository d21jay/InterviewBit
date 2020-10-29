void Solution::setZeroes(vector<vector<int> > &A) {
    bool r0, c0;
    r0 = false; c0 = false;
    for(int i = 0; i < A.size(); i++) {
        if(A[i][0] == 0) {
            c0 = true;
            break;
        }
    }
    for(int i = 0; i < A[0].size(); i++) {
        if(A[0][i] == 0) {
            r0 = true;
            break;
        }
    }
    for(int i = 1; i < A.size(); i++) {
        for(int j = 1; j < A[0].size(); j++) {
            if(A[i][j] == 0) {
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }
    for(int i = 1; i < A.size(); i++) {
        if(A[i][0] == 0) {
            for(int j = 1; j < A[0].size(); j++) A[i][j] = 0;
        }
    }
    for(int j = 1; j < A[0].size(); j++) {
        if(A[0][j] == 0) {
            for(int i = 1; i < A.size(); i++) A[i][j] = 0;
        }
    }
    if(c0) {
        for(int i = 0; i < A.size(); i++) A[i][0] = 0;
    }
    if(r0) {
        for(int j = 0; j < A[0].size(); j++) A[0][j] = 0;
    }
    return;
}