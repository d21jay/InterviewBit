string Solution::solve(string A, int B) {
    vector<int> count;
    count.push_back(1);
    for(int i = 1; i < A.size(); i++) {
        if(A[i] == A[i - 1]) count.push_back(count[i - 1] + 1);
        else count.push_back(1);
    }
    for(int i = 0; i < A.size(); i++) {
        if(count[i] == B) {
            if(i == A.size() - 1 || count[i + 1] == 1) {
                for(int j = i; j > i - B; j--) count[j] = 0;
            }
        }
    }
    string ans = "";
    for(int i = 0; i < count.size(); i++) if(count[i] != 0) ans.push_back(A[i]);
    return ans;
}