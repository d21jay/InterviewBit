vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> ans;
    if(A<1) return ans;
    ans.push_back({1});
    if(A==1) return ans;
    ans.push_back({1,1});
    if(A==2) return ans;
    for(int i = 3; i <= A; i++){
        vector<int> temp;
        temp.push_back(1);
        for(int j = 1; j<i-1; j++){
            temp.push_back(ans[i-2][j-1]+ans[i-2][j]);
        }
        temp.push_back(1);
        ans.push_back(temp);
    }
    return ans;
}