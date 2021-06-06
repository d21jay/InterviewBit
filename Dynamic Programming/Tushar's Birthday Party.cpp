void engine(const vector<int> &B, const vector<int> &C, int val, vector<int> &cost) {
    int curr = INT_MAX;
    for(int i = 0; i < B.size(); i++) {
        if(val > B[i]) {
            if (cost[val - B[i]] == 0) engine(B, C, val - B[i], cost);
            curr = min(curr, cost[val - B[i]] + C[i]);
        }
        else if(B[i] == val) {
            curr = min(curr, C[i]);
        }
    }
    cost[val] = curr;
}
 
int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int maxCap = A[0];
    for(int i = 1; i < A.size(); i++) maxCap = max(maxCap, A[i]);
    vector<int> cost(maxCap + 1, 0);
    int ans = 0;
    for(int i = 0; i < A.size(); i++) {
        if(cost[A[i]] == 0) engine(B, C, A[i], cost);
        ans += cost[A[i]];
    }
    return ans;
}