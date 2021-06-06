int Solution::solve(int A) {
    int mod = 1000000007;
    if(A < 1) return 0;
    long long int threes = 24;
    long long int twos = 12;
    long long int temp;
    for(int i = 1; i < A; i++) {
        temp = ((threes * 11)%mod + (twos * 10)%mod)%mod;
        twos = ((threes * 5)%mod + (twos * 7)%mod)%mod;
        threes = temp;
    }
    return (int)((twos + threes)%mod);
}