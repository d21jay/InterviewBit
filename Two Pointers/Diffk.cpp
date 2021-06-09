int Solution::diffPossible(vector<int> &A, int B) {
    if(A.size() < 2) return 0;
    int i = 0, j = 1;
    int d;
    while(j < A.size()) {
        d = A[j] - A[i];
        if(d == B) {
            if(i != j) return 1;
            else j++;
        }
        else if(d > B) i++;
        else j++;
    }
    return 0;
}