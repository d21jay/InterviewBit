int Solution::solve(string A, string B, vector<string> &C) {
    if(A == B) return 1;
    unordered_set<string> dict;
    queue<pair<string,int>> q;
    for(int i = 0; i < C.size(); i++) dict.insert(C[i]);
    q.push({A, 1});
    int t;
    string s, w;
    while(!q.empty()) {
        s = q.front().first;
        t = q.front().second;
        q.pop();
        t++;
        for(int i = 0; i < A.size(); i++) {
            w = s;
            for(char x = 'a'; x <= 'z'; x++){
                if(s[i] != x) {
                    w[i] = x;
                    if(w == B) return t;
                    if(dict.find(w) != dict.end()){
                        dict.erase(w);
                        q.push({w, t});
                    }
                }
            }
        }
    }
    return 0;
}