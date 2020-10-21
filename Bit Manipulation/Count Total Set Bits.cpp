int Solution::solve(int A) {
    long long int k = 1;
    int mod = 1000000007;
    A++;
    //as 0 is our start in complete seq, hence A++.
    long long int count = 0;
    int temp;
    while(k < A) {
        k *= 2;
        temp = A - (A % k);
        count = (count + temp / 2) % mod;
        if((A - temp) > (k/2)) {
            temp = A - temp - k/2;
            count = (count + temp) % mod;
        }
    }
    return (int) count;
}
//O(log A) which is constant run time as log A <= 32;