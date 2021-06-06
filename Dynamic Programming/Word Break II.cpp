vector<string> Solution::wordBreak(string A, vector<string> &B) {
    unordered_set<string> dict;
    for(int i = 0; i < B.size(); i++) {
        dict.insert(B[i]);
    }
    vector<vector<string>>table(A.size(), vector<string>{});
    string temp;
    for(int i = 0; i < A.size(); i ++) {
        if(i != 0 && table[i - 1].size() == 0) continue;
        temp = "";
        for(int j = i; j < A.size(); j++) {
            temp += A[j];
            if(dict.find(temp) != dict.end()) {
                if(i == 0) table[j].push_back(temp);
                else {
                    for(int k = 0; k <table[i - 1].size(); k++) {
                        table[j].push_back(table[i - 1][k] + " " + temp);
                    }
                }
            }
        }
    }
    vector<string> ans = table[A.size() - 1];
    sort(ans.begin(), ans.end());
    return ans;
}