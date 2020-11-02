int Solution::seats(string A) {
    int medianIndex;
    int MOD = 10000003;
    int count = 0;
    int iSum = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == 'x') count++;
    }
    if(count == 0) return 0;
    count = (count + 1)/2;
    int j = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == 'x') j++;
        if(j == count) {
            medianIndex = i;
            break;
        }
    }
    int ans = 0;
    int curr = medianIndex;
    for(int i = medianIndex; i >=0; i--) {
        if(A[i] == 'x') {
            ans = (ans + curr - i) % MOD;
            curr--;
        }
    }
    curr = medianIndex + 1;
    for(int i = curr; i < A.size(); i++) {
        if(A[i] == 'x') {
            ans = (ans + i - curr) % MOD;
            curr++;
        }
    }
    return ans;
}