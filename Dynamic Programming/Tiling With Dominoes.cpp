int Solution::solve(int A) {
    int mod = 1000000007;
    if(A < 2) return 0;
    else if(A == 2) return 3;
    if(A%2 == 1) return 0;
    A /= 2;
    long long int table[A + 1];
    table[0] = 1;
    table[1] = 3;
    for(int i = 2; i <= A; i++) {
        table[i] = (table[i - 1] * 4  - table[i - 2]) % mod;
        if(table[i] < 0) table[i] += mod;
    }
    return (int)table[A];
}