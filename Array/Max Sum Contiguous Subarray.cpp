int Solution::maxSubArray(const vector<int> &A) {
    if(A.size() < 1) return 0;
    int sum = A[0];
    int k = sum;
    for(int i = 1; i < A.size(); i++) {
        if(k < 0) k = 0;
        k += A[i];
        if(k > sum) sum = k;
    }
    return sum;
}
//O(n)