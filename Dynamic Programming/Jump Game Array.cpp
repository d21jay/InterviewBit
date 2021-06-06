int Solution::canJump(vector<int> &A) {
    int count = 0;
    for(int i = A.size() - 2; i >= 0; i--) {
        if(A[i] == 0) count++;
        else if(count > 0) {
            if(A[i] > count) count = 0;
            else count++;
        }
    }
    if(count == 0) return 1;
    else return 0;
}