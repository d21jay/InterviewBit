int Solution::solve(vector<int> &A) {
    unordered_map<int, int> nums;
    int ans = A.size();
    for(int i = 0; i < A.size(); i++) {
        if(nums.find(A[i]) == nums.end()) nums.insert({A[i], i});
        else ans = min(ans, nums[A[i]]);
    }
    if(ans == A.size()) return -1;
    else return A[ans];
}