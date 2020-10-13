int Solution::repeatedNumber(const vector<int> &A) {
    //O(sqrt(n)) space.
    //worth only for sqrt(n) > 32 i.e. n > 1024. otherwise keep a O(n) bool array.
    int n = A.size() - 1;
    int rn = (int) sqrt(n);
    int space = n/rn;
    if((n%rn) != 0) space++;
    
    vector<int> B(space, 0);
    for(int i = 0; i <= n; i++){
        B[(A[i]-1)/rn]++;
    }
    int overIndex = space - 1;
    //last index can accomodate either n%rn or rn(if n%rn == 0) non-dup elem.
    //so setting it to default overIndex to avoid extra cases.
    //this would work as there would be atleast one dup. (coz A.size() == n+1 > n).
    //if A had size n or less then the mentioned extra case must be checked.
    for(int i = 0; i < space - 1; i++) {
        if(B[i] > rn) {
            overIndex = i;
            break;
        }
    }
    int ans;
    for(int i = 0; i <= n; i++) {
        if((A[i] - 1) >= rn*overIndex && (A[i] - 1) < rn*(overIndex+1)) {
            if(B[A[i] - rn*overIndex - 1] == -1) {
                ans = A[i];
                break;
            }
            B[A[i] - rn*overIndex - 1] = -1;
        }
    }
    return ans;
}
