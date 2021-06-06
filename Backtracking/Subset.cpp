void engine(vector<vector<int>> &ans, vector<int> &tmp, vector<int> &A, int ind){
    ans.push_back(tmp);
    for(int i = ind; i < A.size(); i++){
        tmp.push_back(A[i]);
        engine(ans, tmp, A, i + 1);
        tmp.pop_back();
    }
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    vector<int> tmp;
    engine(ans, tmp, A, 0);
    return ans;
}