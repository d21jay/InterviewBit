int Solution::wordBreak(string A, vector<string> &B) {
    vector<bool> vb(A.size() + 1, false);
    vb[0] = true;
    string s;
    //length of string can't be greater than 20;
    vector<unordered_set<string>>vus(20, unordered_set<string>());
    for(int i = 0; i < B.size(); i++) vus[B[i].size() - 1].insert(B[i]);
    for(int i = 1; i <= A.size(); i++) {
        if(!vb[i - 1]) continue;
        for(int j = 1; j <= 20; j++) {
            if(j + i - 1 > A.size()) break;
            s = A.substr(i - 1, j);
            if(vus[j - 1].find(s) != vus[j - 1].end()) vb[i - 1 + j] = true;
        }
    }
    return (int) vb[A.size()];
}