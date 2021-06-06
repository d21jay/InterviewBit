int Solution::titleToNumber(string A) {
    int ans = 0;
    int x;
    for(int i = 0; i < A.size(); i++) {
        x = A[i] - 'A' + 1;
        ans = ans*26 + x;
    }
    return ans;
}