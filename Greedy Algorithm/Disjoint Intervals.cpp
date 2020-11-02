bool cc(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}
int Solution::solve(vector<vector<int> > &A) {
    int ans = 0;
    sort(A.begin(), A.end(), cc);
    int lend = 0;
    //since all are +ve;
    for(int i = 0; i < A.size(); i++) {
        if(A[i][0] > lend) {
            ans++;
            lend = A[i][1];
        }
    }
    return ans;
}