vector<int> Solution::findPerm(const string A, int B) {
    int lb = 1;
    int rb = B;
    vector<int> sol;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == 'D') {
            sol.push_back(rb);
            rb--;
        }
        else {
            sol.push_back(lb);
            lb++;
        }
    }
    sol.push_back(lb);
    return sol;
}