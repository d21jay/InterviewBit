vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int>> sol;
    vector<int> temp;
    int i, j;
    for(int k = 0; k < A.size(); k++) {
        temp.clear();
        j = k;
        i = 0;
        while(j >= 0) {
            temp.push_back(A[i][j]);
            i++; j--;
        }
        sol.push_back(temp);
    }
    for(int k = 1; k < A.size(); k++) {
        temp.clear();
        i = k;
        j = A.size() - 1;
        while(i < A.size()) {
            temp.push_back(A[i][j]);
            i++; j--;
        }
        sol.push_back(temp);
    }
    return sol;
}