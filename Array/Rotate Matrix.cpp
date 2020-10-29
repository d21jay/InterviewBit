void Solution::rotate(vector<vector<int> > &A) {
    int x = A.size();
    int temp;
    for(int i = 0; i < x/2; i++) {
        for(int j = i; j < (x - i - 1);  j++) {
            temp = A[j][x - i - 1];
            A[j][x - i - 1] = A[i][j];
            A[i][j] = A[x - j - 1][i];
            A[x - j - 1][i] = A[x - i - 1][x - j - 1];
            A[x- i - 1][x - j - 1] = temp;
        }
    }
    return;
}