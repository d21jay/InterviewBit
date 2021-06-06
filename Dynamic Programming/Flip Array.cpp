int Solution::solve(const vector<int> &A) {
    if(A.size() == 0) return 0;
    int sum = 0;
    for(int i = 0; i < A.size(); i++) sum += A[i];
    sum /= 2;
    vector<int> flips(sum + 1, INT_MAX);
    flips[sum] = 0;
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < sum; j++) {
            if(A[i] + j <= sum && flips[A[i] + j] != INT_MAX) {
                flips[j] = min(flips[j], flips[A[i] + j] + 1);
            }
        }        
    }
    for(int i = 0; i <= sum; i++) {
        if(flips[i] != INT_MAX) return flips[i]; 
    }
}