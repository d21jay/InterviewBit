int Solution::solve(vector<int> &A) {
    if(A.size() == 0) return 0;
    int sum = 0;
    vector<int> sumn;
    sumn.push_back(0);
    for(int i = 0; i < A.size(); i++) {
        sum += A[i];
        sumn.push_back(sum);
    }
    int x;
    vector<vector<int>> ans(A.size(), vector<int> (A.size()));
    for(int i = 1; i < A.size(); i++) {
        for(int j = 0; i + j < A.size(); j++) {
            x = INT_MAX;
            for(int k = 0; k < i; k++) {
                x = min(x, ans[k][j] + ans[i - k - 1][j + k + 1]);
            }
            ans[i][j] = x + sumn[i + j + 1] - sumn[j];
        }
    }
    return ans[A.size() - 1][0];
}