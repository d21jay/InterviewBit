int Solution::solve(vector<int> &A, int B) {
    //Assuming positive numbers. for neg numbers, soln would be different.
    vector<vector<int>> sum(A.size(), vector<int>(B + 1, 0));
    for(int i = 1; i <= B; i++) {
        if(A[0] <= i) sum[0][i] = A[0];
    }
    for(int i = 1; i < A.size(); i++) {
        for(int j = 0; j <= B; j++) {
            if(A[i] <= j) sum[i][j] = max(sum[i - 1][j - A[i]] + A[i], sum[i - 1][j]);
            else sum[i][j] = sum[i - 1][j];
        }
    }
    return sum[A.size() -1][B] == B;
}