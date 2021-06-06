int Solution::solve(vector<string> &A) {
    vector<double> C;
    double x;
    double Bm1, Bm2, Bm3, Bma1, Bma2, Bma3;
    Bm1 = 2;
    Bm2 = 2;
    Bma1 = -2;
    Bma2 = -2;
    Bma3 = -2;
    double Cm1, Cm2;
    Cm1 = 2;
    Cm2 = 2;
    double Dm1 = 2;
    double trig = 2;
    trig /= 3;
    for(int i = 0; i < A.size(); i++) {
        x = stod(A[i]);
        if(x >= 1) Dm1 = min(Dm1, x);
        else if(x >= trig) {
            if(x < Cm1) {
                Cm2 = Cm1;
                Cm1 = x;
            }
            else if(x < Cm2) {
                Cm2 = x;
            }
            C.push_back(x);
        }
        else if(x > 0) {
            if(x < Bm1) {
                Bm2 = Bm1;
                Bm1 = x;
            }
            else if(x < Bm2) {
                Bm2 = x;
            }
            if(x > Bma1) {
                Bma3 = Bma2;
                Bma2 = Bma1;
                Bma1 = x;
            }
            else if(x > Bma2) {
                Bma3 = Bma2;
                Bma2 = x;
            }
            else if(x > Bma3) {
                Bma3 = x;
            }
        }
    }
    if(Bma1 + Bma2 + Bma3 > 1) return 1;
    if(Bm1 + Bm2 + Dm1 < 2) return 1;
    if(Bm1 + Cm1 + Dm1 < 2) return 1;
    if(Bm1 + Cm1 + Cm2 < 2) return 1;
    for(int i = 0; i < C.size(); i++) {
        if(Bma1 + Bma2 + Cm1 > 1 && Bma1 + Bma2 + Cm1 < 2) return 1;
        // this works coz for any Cm1, if it doesn't work then Bma1 + Bma2 is atleast 1;
        // then if there is another B then Bma1 + Bma2 + B already works.
    }
    return 0;
}
//O(n)