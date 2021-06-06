vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> ans = B;
    vector<vector<int>> temp = B;
    for(int i = 0; i < A; i++) {
        for(int i = 0; i < B.size(); i++) {
            for(int j = 0; j < B[0].size(); j++) {
                if(i > 0) temp[i][j] = max(temp[i][j], ans[i - 1][j]);
                if(j > 0) temp[i][j] = max(temp[i][j], ans[i][j - 1]);
                if(i <  B.size() - 1) temp[i][j] = max(temp[i][j], ans[i + 1][j]);
                if(j < B[0].size() - 1) temp[i][j] = max(temp[i][j], ans[i][j + 1]);
            }
        }
        ans = temp;
    }
    return ans;
}