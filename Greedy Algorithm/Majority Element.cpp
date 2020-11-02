int Solution::majorityElement(const vector<int> &A) {
    //beliving in problem statement that majority element always exists.
    int count = 0;
    int ans;
    for(int i = 0; i < A.size(); i++) {
        if(count == 0) {
            ans = A[i];
            count++;
        }
        else if(A[i] == ans) count ++;
        else count--;
    }
    return ans;
}