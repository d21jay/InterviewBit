string Solution::solve(string A) {
    char c;
    string s = "";
    vector<string> ans;
    for(int i = 0; i < A.size(); i++) {
        c = A[i];
        if(c == ' ') {
            if(s.size() > 0) {
                ans.push_back(s);
                s = "";
            }
        }
        else s.push_back(c);
    }
    if(s.size() > 0) ans.push_back(s);
    s = "";
    if(ans.size() > 0) s = ans[ans.size() - 1];
    for(int i = ans.size() - 2; i >= 0; i--) {
        s = s + " " + ans[i];
    }
    return s;
}