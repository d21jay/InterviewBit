vector<vector<int>> ans;
void engine(int ind, vector<int> &tmp, vector<int> &A) {
    ans.push_back(tmp);
    if(ind == A.size()) return;
    bool sent = false;
    int last;
    for(int i = ind; i < A.size(); i++) {
        if(sent == true && last == A[i]) continue;
        sent = true;
        last = A[i];
        tmp.push_back(last);
        engine(i + 1, tmp, A);
        tmp.pop_back();
    }
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(), A.end());
    ans = *(new vector<vector<int>>);
    vector<int> tmp;
    engine(0, tmp, A);
    return ans;
}