int Solution::nchoc(int A, vector<int> &B) {
    long long int ans = 0;
    int t;
    make_heap(B.begin(), B.end());
    for(int i = 0; i < A; i++){
        t = B.front();
        ans = (ans + t) % 1000000007;
        pop_heap(B.begin(), B.end());
        B[B.size() - 1] = t/2;
        push_heap(B.begin(), B.end());
    }
    return (int) ans;
}