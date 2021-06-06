int Solution::solve(vector<int> &A, int B) {
    if(B == 0) return 0;
    int ans = 0;
    unordered_set<int> keys;
    for(int i = 0; i < A.size(); i++) {
        keys.insert(A[i]);
    }
    for(int i = 0; i < A.size(); i++) {
        if(keys.find(A[i]^B) != keys.end()) ans++;
    }
    return ans/2;
}