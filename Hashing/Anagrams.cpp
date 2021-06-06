vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<string, int> ind;
    string s;
    vector<vector<int>> ans;
    for(int i = 0; i < A.size(); i++) {
        s = A[i];
        sort(s.begin(), s.end());
        if(ind.find(s) == ind.end()) {
            ind.insert({s, ans.size()});
            ans.push_back({i + 1});
        }
        else ans[ind[s]].push_back(i + 1);
    }
    return ans;
}