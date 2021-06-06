int Solution::lengthOfLongestSubstring(string A) {
    int ans = 0;
    unordered_map<char, int> lo;
    int rei = -1;
    for(int i = 0; i < A.size(); i++) {
        if(lo.find(A[i]) == lo.end()){
            lo.insert({A[i], i});
        }
        else{
            rei = max(rei, lo[A[i]]);
            lo[A[i]] = i;
        }
        ans = max(ans, i - rei);
    }
    return ans;
}