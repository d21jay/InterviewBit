int Solution::solve(vector<vector<int> > &A) {
    int ans = 0;
    int sum;
    for(int i = 0; i < A.size(); i++) {
        sum = 0;
        unordered_map<int, int> ump;
        ump.insert({0, 1});
        for(int j = 0; j < A[0].size(); j++) {
            sum += A[i][j];
            A[i][j] = sum;
            if(ump.find(sum) != ump.end()) {
                ans += ump[sum];
                ump[sum]++;
            }
            else ump.insert({sum, 1});
        }
    }
    vector<vector<int>> B = A;
    for(int i = 1; i < A.size(); i++) {
        for(int j = 0; j < A.size() - i; j++) {
            unordered_map<int, int> ump;
            ump.insert({0, 1});
            for(int k = 0; k < A[0].size(); k++) {
                B[j][k] += A[j + i][k];
                if(ump.find(B[j][k]) != ump.end()) {
                    ans += ump[B[j][k]];
                    ump[B[j][k]]++;
                }
                else ump.insert({B[j][k], 1});
            }
        }
    }
    return ans;
}