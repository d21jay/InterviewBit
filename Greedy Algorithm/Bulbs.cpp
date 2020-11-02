int Solution::bulbs(vector<int> &A) {
    int ans = 0;
    int trig = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == trig) {
            ans++;
            trig ^= 1;
        }
    }
    return ans;
}