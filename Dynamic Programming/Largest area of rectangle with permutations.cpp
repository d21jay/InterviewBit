int Solution::solve(vector<vector<int> > &A) {
    if(A.size() == 0) return 0;
    int ans = 0;
    int count;
    int hist[A.size() + 1];
    for(int i = 1; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            if(A[i][j] == 1) A[i][j] += A[i - 1][j];
        }
    }
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j <= A.size(); j++) hist[j] = 0;
        for(int j = 0; j < A[0].size(); j++) {
            hist[A[i][j]]++;
        }
        count = 0;
        for(int j = A.size(); j > 0; j--) {
            count += hist[j];
            if(hist[j] > 0) ans = max(ans, count * j);
        }
    }
    return ans;
}
//O(n*m) time O(n) space.