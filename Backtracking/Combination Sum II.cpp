vector<vector<int>> ans;
void engine(vector<int> &A, vector<int> &tmp, int B, int t, int ind) {
    int last;
    bool sent = false;
    for(int i = ind; i < A.size(); i++) {
        if(sent == true && A[i] == last) continue;
        sent = true;
        last = A[i];
        t += A[i];
        if(t > B) return;
        tmp.push_back(A[i]);
        if(t == B) {
            ans.push_back(tmp);
            tmp.pop_back();
            return;
        }
        engine(A, tmp, B, t, i + 1);
        tmp.pop_back();
        t -= A[i];
    }
    
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    ans = *(new vector<vector<int>>);
    vector<int> tmp;
    sort(A.begin(), A.end());
    engine(A, tmp, B, 0, 0);
    return ans;
}