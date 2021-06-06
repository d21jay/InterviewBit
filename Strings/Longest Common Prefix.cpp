string Solution::longestCommonPrefix(vector<string> &A) {
    string ans = "";
    if(A.size() == 0) return ans;
    int minSize = A[0].size();
    for(int i = 1; i < A.size(); i++) minSize = min(minSize, (int)A[i].size());
    char c;
    for(int i = 0; i < minSize; i++) {
        c = A[0][i];
        for(int j = 1; j < A.size(); j++) {
            if(A[j][i] != c) return ans;
        }
        ans.push_back(c);
    }
    return ans;
}