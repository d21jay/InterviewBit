vector<vector<int>> ans;
vector<bool> mark;
void engine(vector<int> &temp, vector<int> &A) {
    if(temp.size() == A.size()) {
        ans.push_back(temp);
        return;
    }
    for(int i = 0; i < A.size(); i++) {
        if(!mark[i]) {
            mark[i] = true;
            temp.push_back(A[i]);
            engine(temp, A);
            temp.pop_back();
            mark[i] = false;
        }
    }
    return;
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    ans = *(new vector<vector<int>>);
    mark = *(new vector<bool>(A.size(), false));
    vector<int> temp;
    engine(temp, A);
    return ans;
}