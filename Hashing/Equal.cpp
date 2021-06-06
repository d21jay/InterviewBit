vector<int> Solution::equal(vector<int> &A) {
    unordered_map<int, vector<int>> sums;
    int s;
    vector<int> ans = {};
    vector<int> t;
    for(int i = 0; i < A.size(); i++){
        for(int j = i + 1; j < A.size(); j++) {
            s = A[i] + A[j];
            if(sums.find(s) != sums.end()) {
                if(sums[s][0] != i && sums[s][1] != i  && sums[s][1] != j) {
                    t = {sums[s][0], sums[s][1], i, j};
                    if(ans.size() == 0 || t < ans) ans = t;
                }
            }
            else sums.insert({s, {i, j}});
        }
    }
    return ans;
}