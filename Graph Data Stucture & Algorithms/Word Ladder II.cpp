vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    if(start == end) return {{start}};
    queue<pair<string, string>> q;
    unordered_map<string, pair<int, vector<vector<string>>>> d;
    for(int i = 0; i < dict.size(); i++) d.insert({dict[i], {-1, {}}});
    d.insert({end, {-1, {}}});
    d.insert({start, {-1, {}}});
    string s, w, t;
    bool found = false;
    q.push({start, ""});
    d[start].second.push_back({start});
    while(!q.empty()) {
        s = q.front().first;
        t = q.front().second;
        if(s == end) found = true;
        q.pop();
        if(d[s].first == -1) {
            if(t == "") d[s].first = 0;
            else {
                d[s].first = d[t].first + 1;
                for(int i = 0; i < d[t].second.size(); i++) {
                    d[s].second.push_back(d[t].second[i]);
                    d[s].second[d[s].second.size() - 1].push_back(s);
                }
            }
            if(found == false) {
                //last chance for previous level guys.
                for(int i = 0; i < s.size(); i++) {
                    w = s;
                    for(char c = 'a'; c < 'z'; c++) {
                        w[i] = c;
                        if(d.find(w) != d.end() && d[w].first == -1) 
                            q.push({w,s});
                    }
                }
            }
        }
        else if(d[t].first + 1 == d[s].first){
            for(int i = 0; i < d[t].second.size(); i++) {
                d[s].second.push_back(d[t].second[i]);
                d[s].second[d[s].second.size() - 1].push_back(s);
            }
        }
    }
    return d[end].second;
}