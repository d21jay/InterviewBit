void engine(vector<string> &ans, string tmp, int o, int c, int t, int A ){
    if(tmp.length() == 2*A) {
       if(t == 0) ans.push_back(tmp);
       return;
    }
    if(o < A) {
        tmp.push_back('(');
        engine(ans, tmp, o+1, c, t+1, A);
        tmp.pop_back();
    }
    if(c < A && t > 0) {
        tmp.push_back(')');
        engine(ans, tmp, o, c+1, t - 1, A);
        tmp.pop_back();
    }
}
vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    string tmp = "";
    engine(ans, tmp, 0, 0, 0, A);
    return ans;
}