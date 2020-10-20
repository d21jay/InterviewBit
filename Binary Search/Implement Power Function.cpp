int Solution::pow(int x, int n, int d) {
    if(d < 0) d *= -1;
    if(n == 0) return 1 % d;
    if(n == 1){
        if(x < 0) return d + x % d;
        return x % d;
    }
    int ans = pow(x, n/2, d);
    ans = (((long long int) ans) * ans) % d;
    if(n%2 == 1) ans = (((long long int ) ans) * x) % d;
    if(ans < 0) return d + ans;
    return ans;
}
//O(log n)