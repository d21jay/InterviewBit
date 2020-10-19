int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    int ans = n + 1;
    //swap integers to correct place without cycling.
    for(int i = 0; i < n; i++) {
        while(A[i] > 0 && A[i] <= n && A[i] != i + 1 && A[A[i] - 1] != A[i]) {
            swap(A[i], A[A[i] - 1]);
        }
    }
    for(int i = 0; i < n; i++) {
        if(A[i] != i + 1) {
            ans = i + 1;
            break;
        }
    }
    return ans;
}
//O(n) time and constant space.