vector<int> Solution::solve(int A, vector<int> &B) {
    //complete greedy solution
    if(B.size() == 0) return {};
    vector<int> ans;
    int m = 0, z;
    for(int i = 1; i < B.size(); i++) {
        if(B[m] > B[i]) m = i;
    }
    z = A/B[m];
    for(int i = 0; i < z; i++) {
        ans.push_back(m);
    }
    A %= B[m];
    int x;
    //this loop can be optimised to O(n) instead of n^2 by keeping array for counters.
    for(int i = 0; i < m; i++) {
        x = B[i] - B[m];
        for(int j = 0; j < ans.size(); j++) {
            if(ans[j] < i) continue;
            if(x <= A) {
                ans[j] = i;
                A -= x;
            }
        }
    }
    return ans;
}