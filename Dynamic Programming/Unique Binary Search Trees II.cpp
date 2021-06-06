int Solution::numTrees(int A) {
    //catalan number
    if(A < 2) return 1;
    long long int ans = 1;
    for(int i = 0; i < A; i++) {
        ans *= (2*A - i);
        ans /=  (i + 1);
    }
    ans /= (A + 1);
    return (int) ans;
}
//O(n) when there is no overflow to be cared.