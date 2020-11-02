int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int currSum = 0;
    int gasDiff = 0;
    int ans;
    for(int i = 0; i < A.size(); i++) {
        currSum += (A[i] - B[i]);
        if(currSum < gasDiff) {
            gasDiff = currSum;
            ans = i + 1;
        }
    }
    if(gasDiff == 0) return 0;
    if(currSum < 0) return -1;
    return ans;
}