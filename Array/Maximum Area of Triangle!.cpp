int Solution::solve(vector<string> &A) {
    int soln = 0;
    int n = A[0].size();
    int rb[n], gb[n], rg[n];
    int er, eg, eb, wb, wg, wr;
    er = -1; eg = -1; eb = -1;
    wr = -1; wg = -1; wb = -1;
    int ur, dr, ug, dg, ub, db;
    //directions : u = uppermost, d = lowermost, w = leftmost, e = rightmost.
    int k;
    for(int  i = 0; i < n; i++){
            ur = -1; dr = -1;
            ug = -1; dg = -1;
            ub = -1; db = -1;
        for(int j = 0; j < A.size(); j++) {
            if(A[j][i] == 'r') {
                if(ur == -1) ur = j;
                dr = j;
                if(wr == -1) wr = i;
                er = i;
            }
            if(A[j][i] == 'g') {
                if(ug == -1) ug = j;
                dg = j;
                if(wg == -1) wg = i;
                eg = i;
            }
            if(A[j][i] == 'b') {
                if(ub == -1) ub = j;
                db = j;
                if(wb == -1) wb = i;
                eb = i;
            }
        }
        k = 0;
        if(ur != -1) {
            if(ug != -1){
                k = ur > ug ? ur - ug : ug - ur;
                if(ur - dg > k) k = ur - dg;
                else if(dg - ur > k) k = dg - ur;
                if(dr - ug > k) k = dr - ug;
                else if(ug - dr > k) k = ug - dr;
                if(dr - dg > k) k = dr - dg;
                else if(dg - dr > k) k = dg - dr;
                k = k + 1;
            }
        }
        rg[i] = k;
        k = 0;
        if(ur != -1) {
            if(ub != -1){
                if(ur - ub > k) k = ur - ub;
                else if(ub - ur > k) k = ub - ur;
                if(ur - db > k) k = ur - db;
                else if(db - ur > k) k = db - ur;
                if(dr - ub > k) k = dr - ub;
                else if(ub - dr > k) k = ub - dr;
                if(dr - db > k) k = dr - db;
                else if(db - dr > k) k = db - dr;
                k = k + 1;
            }
        }
        rb[i] = k;
        k = 0;
        if(ug != -1) {
            if(ub != -1){
                if(ug - ub > k) k = ug - ub;
                else if(ub - ur > k) k = ub - ug;
                if(ug - db > k) k = ug - db;
                else if(db - ug > k) k = db - ug;
                if(dg - ub > k) k = dg - ub;
                else if(ub - dg > k) k = ub - dg;
                if(dg - db > k) k = dg - db;
                else if(db - dg > k) k = db - dg;
                k = k + 1;
            }
        }
        gb[i] = k;
    }
    for(int i = 0; i < n; i++) {
        if(wg != -1) {
            k = ceil((0.5)*rb[i] * (i - wg + 1));
            if(k > soln) soln = k;
            k = ceil((0.5)*rb[i] * (eg - i + 1));
            if(k > soln) soln = k;
        }
        if(wb != -1) {
            k = ceil((0.5)*rg[i] * (i - wb + 1));
            if(k > soln) soln = k;
            k = ceil((0.5)*rg[i] * (eb - i + 1));
            if(k > soln) soln = k;
        }
        if(wr != -1) {
            k = ceil((0.5)*gb[i] * (i - wr + 1));
            if(k > soln) soln = k;
            k = ceil((0.5)*gb[i] * (er - i + 1));
            if(k > soln) soln = k;
        }
    }
    return soln;
}
/*
some test cases' expected outputs are wrong:
for test case:
16 rbbbggrbrbrggrgr bgbrbbrgggrgrrrr rgbrrrbbgbbbrrrb bbgbrgrbbrgrrgbb ggbrbrrbggggrrgb bgbrbrggbgrrgbrg grbbbgrbgbbgbbgr rbgbgbrrgrgbgbbr gbgrrgbbrrbbgbbg brgrbbrrbrgbgbrb rbbrrrbgrbgrbbrg rrggrrbbbrgbgggg rrrrgbbrgbbgbbrg rgbgrrrrggbbrrgr ggbrbbbbgrrrbrbb gggggrgbrbrbrrgr 
#
R#b b b g g r b r b r g g r g r 1
b g b r b b r g g g r g r r r r 2
r g b r r r b b g b b b r r r b 3
b b g b r g r b b r g r r g b#B#4
g g b r b r r b g g g g r r g b 5
b g b r b r g g b g r r g b r g 6
g r b b b g r b g b b g b b g r 7
r b g b g b r r g r g b g b b r 8
g b g r r g b b r r b b g b b g 9
b r g r b b r r b r g b g b r b 10
r b b r r r b g r b g r b b r g 11
r r g g r r b b b r g b g g g g 12
r r r r g b b r g b b g b b r g 13
r g b g r r r r g g b b r r g r 14
g g b r b b b b g r r r b r b b 15
G#g g g g r g b r b r b r r g r 16
#
1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6
0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1

The r at [0][0] g at [15][0] and B[3][15]
forms a largest triangle. (Take any B in last column)

0.5*16*16 = 128 not 120
*/