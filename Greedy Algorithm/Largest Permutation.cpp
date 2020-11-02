vector<int> Solution::solve(vector<int> &A, int B) {
    //unique integers from 1 to N. :-)
    vector<int> pos(A.size());
    for(int i = 0; i < A.size(); i++) {
        pos[A[i] - 1] = i;
    }
    int li = A.size() - 1;
    for(int i = 0; i < A.size(); i++) {
        if(B < 1) break;
        if(A[i] != li + 1) {
            pos[A[i] - 1] = pos[li];
            swap(A[i], A[pos[li]]);
            B--;
        }
        li--;
    }
    return A;
}