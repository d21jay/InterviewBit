int Solution::solve(const vector<int> &A) {
    vector<unordered_map<int, int>> mv(A.size(), unordered_map<int,int>());
    int ans = 1;
    int d;
    for(int i = 0; i < A.size(); i++) mv[i][0] = 1;
    for(int i = 1; i < A.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(mv[j].find(A[j] - A[i]) == mv[j].end()) d = 2;
            else d = mv[j][A[j] - A[i]] + 1;
            ans = max(ans, d);
            mv[i][A[j] - A[i]] = d;
        }
    }
    return ans;
}