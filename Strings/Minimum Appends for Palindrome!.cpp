int Solution::solve(string A) {
    int i, j;
    j = A.size() - 1;
    int ans;
    while(i < j) {
        if(A[i] != A[j]) {
            j = A.size() - 1;
            ans = i + 1;
        }
        else j--;
        i++;
    }
    return ans;
}