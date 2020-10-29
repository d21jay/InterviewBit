int Solution::solve(vector<int> &A) {
    int count[A.size() + 1] = {0};
    bool set[A.size() + 1] = {false};
    for(int i = 0; i < A.size(); i++) {
        if(A[i] > 0 && A[i] < A.size() + 1) {
            count[A[i] - 1]++;
        }
        //A.size() is unsigned int, so careful with negs.
        else if(A[i] >= (int)(A.size() + 1)) count[A.size()]++;
        if(A[i] >= 0 && A[i] < A.size() + 1) set[A[i]] = true;
    }
    for(int i = A.size() - 1; i >= 0; i--) {
        count[i] += count[i + 1];
    }
    for(int i = 0; i < A.size() + 1; i++) {
        if(count[i] == i && set[i]) return 1;
    }
    return -1;
}
//O(n) time and space.