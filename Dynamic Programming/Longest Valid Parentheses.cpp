int Solution::longestValidParentheses(string A) {
    //looks like largest sum subarry.
    //but need non-zero positive sums also;
    //n^2 is trivial. and can be done using stacks.
    int ans = 0;
    int sum = 0;
    vector<int> record(A.size() + 1, 0);
    for(int i = 0; i <= A.size(); i++) record[i] = -2;
    record[0] = -1;
    //record is first occurence of sum in current valid stream.
    int lastCut = 0; //This is hero step. making algo from n^2 to O(n);
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == ')') {
            sum += -1;
            if(sum < 0) {
                sum = 0;
                record[0] = i;
            }
            else ans = max(ans, i - record[sum]);
            lastCut = sum;
        }
        else if(A[i] == '(') {
            sum += 1;
            if(sum > lastCut) record[sum] = i;
        }
    }
    return ans;
}
//The straight DP solution of this problem is so yuck;
//this version of DP on derived problem is more intutive to me.  