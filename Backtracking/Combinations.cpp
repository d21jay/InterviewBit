vector<vector<int>>ans;
void engine(vector<int> &tmp, int pos, int A, int B) {
    if(tmp.size() == B){
        ans.push_back(tmp);
        return;
    }
    for(int i = pos; i <= A; i++){
        tmp.push_back(i);
        engine(tmp, i + 1, A, B);
        tmp.pop_back();
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    ans = *(new vector<vector<int>>);
    if(B > A || A < 1) return ans;
    vector<int> tmp;
    engine(tmp, 1, A, B);
    return ans;
}