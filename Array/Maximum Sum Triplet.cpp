int Solution::solve(vector<int> &A) {
    vector<int> gAfter(A.size(), INT_MIN);
    for(int i = A.size() - 2; i >= 0; i--) {
        gAfter[i] = max(gAfter[i + 1], A[i + 1]);
    }
    int tSum = 0;
    int gBefore, cSum;
    set<int> sorted;
    set<int>:: iterator it;
    sorted.insert(A[0]);
    for(int i = 1; i < A.size() - 1; i++){
        it = sorted.lower_bound(A[i]);
        if(gAfter[i] > A[i] && it != sorted.begin()) {
            it--;
            gBefore = *it;
            cSum = gBefore + A[i] + gAfter[i];
            tSum = max(tSum, cSum);
        }
        sorted.insert(A[i]);
    }
    return tSum;
}
O(nlogn) time.