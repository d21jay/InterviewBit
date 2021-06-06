int Solution::jump(vector<int> &A) {
    int count = 0;
    int i = 0;
    int x;
    int m;
    while(i < A.size() - 1) {
        count++;
        x = A[i];
        if(x == 0) return -1;
        m = i + 1;
        for(int j = 2; j <= x; j++) {
            if(i + j == A.size() - 1) return count;
            if(i + j + A[i + j] > m + A[m]) m = i + j;
        }
        i = m;
    }
    return count;
}