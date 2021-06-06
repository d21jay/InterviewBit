vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    if(B.size() == 0) return {};
    vector<int> ans;
    int ss = B[0].size();
    int k = ss * B.size();
    if(A.size() < k) return {};
    unordered_map<string, int> umap;
    unordered_map<string, int> tmap;
    for(int i = 0; i < B.size(); i++) {
        if(umap.find(B[i]) != umap.end()) umap[B[i]]++;
        umap.insert({B[i], 1});
    }
    int t;
    string s;
    bool pass = false;
    for(int i = 0; i <= A.size() - k; i++) {
        t = i;
        pass = true;
        tmap = umap;
        for(int j = 0; j < B.size(); j++) {
            s = A.substr(t, ss);
            if(tmap.find(s) == tmap.end() || tmap[s] == 0) {
                pass = false;
                break;
            }
            tmap[s]--;
            t += ss;
        }
        if(pass) ans.push_back(i);
    }
    return ans;
}