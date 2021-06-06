int Solution::solve(string A) {
    int c = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == '(') c++;
        else if(A[i] == ')') c--;
        if(c < 0) return 0;
    }
    if(c != 0) return 0;
    return 1;
}