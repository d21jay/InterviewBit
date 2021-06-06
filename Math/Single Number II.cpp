int Solution::singleNumber(const vector<int> &A) {
    vector<int> abit(32, 0);
    int x, a;
    for(int i = 0; i < A.size(); i++) {
        a = A[i];
        for(int j = 0; j < 32; j++) {
            x = a & 1;
            abit[j] += x;
            a = a>>1;
        }
    }
    int ans = 0;
    for(int i = 31; i >= 0; i--) {
        ans = ans<<1;
        if(abit[i]%3 != 0) ans += 1;
    }
    return ans;
}