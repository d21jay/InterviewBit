int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    if(A.size() < 2) return 0;
    int ans = 0;
    int sx, sy;
    sx = A[0];
    sy = B[0];
    for(int i = 1; i<A.size();i++){
        ans += max(abs((A[i] - sx)), abs((B[i] - sy)));
        sx = A[i];
        sy = B[i];
    }
    
    return ans;
}