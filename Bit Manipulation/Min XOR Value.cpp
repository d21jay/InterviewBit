int Solution::findMinXor(vector<int> &A) {
    //first trying (nlog n) soln
    sort(A.begin(), A.end());
    int minXor = A[A.size()-1]*2;
    for(int i = 0; i < A.size() - 1; i++) {
        minXor = minXor < (A[i]^A[i + 1]) ? minXor : A[i]^A[i + 1];   
    }
    return minXor;
}
//now trie approach will take O(n) technically.
//but it is actually O(31*n) thus sorting approach would be better till ~~INT_MAX size A.
/*
but technically use trie for arbitary large size.
however, DESTROY A while creating trie otherwise it would take extra O(n) space.
*/