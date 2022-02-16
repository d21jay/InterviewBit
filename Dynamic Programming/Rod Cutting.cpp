vector<int> Solution::rodCut(int A, vector<int> &B) {
    vector<int> ans;
    vector<int> t = B;
    B = {0};
    B.insert(B.end(), t.begin(), t.end());
    B.push_back(A);
    int l, r;
    vector<vector<pair<int, int>>> table(B.size(), vector<pair<int, int>>(B.size(), {INT_MAX, -1}));
    for(int i = 0; i < B.size(); i++) table[i][i].first = 0;
    for(int i = 1; i < B.size(); i++) {
        for(int j = 0; j + i < B.size(); j++) {
            for(int k = j + 1; k < i + j; k++){
                l = table[j][k].first;
                r = table[k][i + j].first;
                if(table[j][i + j].first > l + r + B[j + i] - B[j]){
                    table[j][i + j].first = l + r + B[j + i] - B[j];
                    table[j][i + j].second = k;
                }
            }
        }
    }
    int c = table[0][B.size() - 1].second;
    l = 0;
    r = B.size() - 1;
    stack<vector<int>> q;
    q.push({c, l, r, 0});
    int x;
    while(!q.empty()){
        c = q.top()[0];
        l = q.top()[1];
        r = q.top()[2];
        x = q.top()[3];
        if(x == 0) q.top()[3] = 1;
        else q.pop();
        if(c != -1) {
            if(x == 0) ans.push_back(B[c]);
            if(x == 0) q.push({table[l][c].second, l, c, 0});
            else q.push({table[c][r].second, c, r, 0});
        }
    }
    return ans;
}
