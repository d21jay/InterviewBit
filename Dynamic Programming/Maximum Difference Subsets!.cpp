int Solution::solve(vector<int> &A) {
    int sum = 0;
    int mv = 0;
    for(int i = 0; i < A.size(); i++) mv = min(mv, A[i]);
    for(int i = 0; i < A.size(); i++) A[i] -= mv;
    for(int i = 0; i < A.size(); i++) sum += A[i];
    int as = sum;
    sum /= 2;
    vector<vector<int>> ts(A.size(), vector<int>(sum + 1, 0));
    for(int i = 1; i <= sum; i++) {
        if(A[0] <= i) ts[0][i] = A[0]; 
    }
    for(int i = 1; i < A.size(); i++) {
        for(int j = 1; j <= sum; j++) {
            if(A[i] <= j) ts[i][j] = max(ts[i - 1][j - A[i]] + A[i], ts[i - 1][j]); 
            else ts[i][j] = ts[i - 1][j];
        }
    }
    return as - 2*(ts[A.size() - 1][sum]);
}