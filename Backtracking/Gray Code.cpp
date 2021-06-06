vector<int> Solution::grayCode(int A) {
    vector<int> ans;
    int tot = 1<<A;
    for(int i = 0; i < tot; i++){
        ans.push_back(i ^ (i>>1));
    }
    return ans;
}