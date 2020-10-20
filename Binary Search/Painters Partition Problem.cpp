int paintersRequired(vector<int> &A, int maxArea) {
    int painters = 1;
    int currArea = 0;
    for(int i = 0; i < A.size(); i++) {
        if(currArea + A[i] > maxArea) {
            currArea = 0;
            painters++;
        }
        currArea += A[i];
    }
    return painters;
}
int Solution::paint(int A, int B, vector<int> &C) {
    int total, max_C;
    total = 0;
    max_C = 0;
    for(int i = 0; i < C.size(); i++) {
        total += C[i];
        max_C = C[i] > max_C ? C[i] : max_C;
    }
    int l = max_C;
    int r = total;
    int m = (l + r)/2;
    int temp, ans;
    while(l <= r) {
        temp = paintersRequired(C, m);
        if(temp > A) l = m + 1;
        else {
            ans = m;
            r = m - 1;
        }
        m = (l + r)/2;
    }
    ans = (((long long int)ans) * B) % 10000003;
    return ans;
}
//O(n^2 log(max_C)) and not O(n logn) or O(n log(max_C))
//becoz x = sum_C - max_c = max_c^n - max_c worst case.
//hence, O(nlogx) = O(n^2 log(max_C)).