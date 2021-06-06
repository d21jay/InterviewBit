struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    unordered_map<pair<double, double>, unordered_set<int>, hash_pair> mc;
    if(A.size() < 3) return A.size();
    int ans = 2;
    double m, c;
    pair<double, double> pair;
    for(int i = 0; i < A.size(); i++) {
        for(int j = i + 1; j < A.size(); j++) {
            if(B[i] - B[j] == 0) {
                pair.first = 4;
                pair.second = B[i];
            }
            else {
                pair.first = ((double) (A[i] - A[j]))/(B[i] - B[j]);
                pair.second = A[i] - pair.first*B[i];
                pair.first = atan(pair.first);
            }
            if(mc.find(pair) == mc.end()) {
                mc.insert({pair, {i, j}});
            }
            else {
                mc[pair].insert({i, j});
                ans = max(ans, (int)mc[pair].size());
            }
        }
    }
    return ans;
}