vector<int> Solution::nextPermutation(vector<int> &A) {
    if(A.size() < 2) return A;
    int lb = INT_MAX;
    int ind, l, r, j, tar, temp;
    ind = -1;
    //find till when it is inincreasing order from reverse. The number next to it should
    //increase by just bigger number encountered till now and tail after it will be in
    //ascending order in next permutation.
    for(int i = A.size() - 2; i >= 0; i--) {
        if(A[i] < A[i + 1]) {
            tar = A[i];
            ind = i;
            break;
        }
    }
    l = ind + 1;
    r = A.size() - 1;
    while(l < r) {
        temp = A[l];
        A[l] = A[r];
        A[r] = temp;
        if(ind > -1) {
            if(A[l] < lb && A[l] > tar) {
                lb = A[l];
                j = l;
            }
            if(A[r] < lb && A[r] > tar) {
                lb = A[r];
                j = r;
            }
        }
        l++; r--;
    }
    if(ind > -1) {
        if(A[r] < lb && A[r] > tar) {
                lb = A[r];
                j = r;
        }
        temp = A[j];
        A[j] = A[ind];
        A[ind] = temp;
    }
    return A;
}
//O(n)