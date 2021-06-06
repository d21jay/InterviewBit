int Solution::chordCnt(int A) {
    int ans[A + 1] = {1};
    int mod = 1000000007;
    int csum;
    long long int temp;
    for(int i = 1; i <= A; i++) {
        csum = 0;
        for(int j = 1; j <= i; j++) {
            temp = ans[j - 1];
            temp = (temp * ans[i - j]) % mod;
            csum = (csum + temp) % mod;
        }
        ans[i] = csum;
    }
    return ans[A];
}
//O(n^2)
//a chord in the circle would divide it into two abstract circles.
//now since a point can have maximum one chord passing in a particular 'way',
//fix a point and pass the chord through other 2*A - 1 point, dividing circles into
//two. However, circles with odd points have 0 ways. so we only have A other points for a
//given fixed point. nd all those even points circle are neat sub-problems. :-)

//goal: use binomial coefficients like in catalan number to do in O(n).
/*
//BIG SPOILER catalan number C(n+1) = C(n) * (2n + 1)(2n + 2) / [(n+1)(n+2)]
// => C(n + 1) = C(n) * (4n + 2) / (n + 2). //DEAD x_x
int Solution::chordCnt(int A) {
    long long int C = 1;
    int mod = 1000000007;
    for(int i = 1; i <= A; i++) {
        C *= (4 * i - 2);
        C /= (i + 1);
    }
    return (int)  (C % mod);
}
//O(n) time. const space.
//but can't handle big inputs. (can't divide after modulo).
*/