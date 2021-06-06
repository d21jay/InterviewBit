int Solution::solve(int A, int B) {
    vector<vector<int>> max_floor(A, vector<int>(B, 0));
    for(int i = 0; i < A; i++) {
        max_floor[i][0] = 1;
    }
    for(int i = 0; i < B; i++) {
        max_floor[0][i] = i + 1;
    }
    int i = 1;
    while(max_floor[A - 1][i - 1] < B) {
        for(int j = 1; j < A; j++) {
            max_floor[j][i] = max_floor[j][i - 1] + 1 + max_floor[j - 1][i - 1];
        }
        i++;
    }
    return i;
}