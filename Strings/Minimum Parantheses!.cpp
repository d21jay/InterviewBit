int Solution::solve(string A) {
    int ans = 0;
    int count = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == ')') {
            count--;
        }
        else if(A[i] == '(') {
            if(count < 0) {
                ans -= count;
                count = 0;
            }
            count++;
        }
    }
    ans = abs(count) + ans;
    return ans;
}