int Solution::minCut(string A) {
    vector<int> ans(A.size(), 0);
    string s1, s2;
    int x;
    for(int i = 0; i < A.size(); i++) {
        x = A.size();
        for(int j = 0; j <= i; j++){
            s1 = A.substr(j, i - j + 1);
            s2 = s1;
            reverse(s2.begin(), s2.end());
            if(s1 == s2) {
                if(j == 0) break;
                else {
                    x = min(x, ans[j - 1] + 1);
                }
            }
            ans[i] = x;
            //things could have been placed better to reduce unneccesary
            //reassingment but ok.
        }
    }
    return ans[A.size() - 1];
}