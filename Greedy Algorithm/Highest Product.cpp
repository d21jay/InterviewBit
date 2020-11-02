int Solution::maxp3(vector<int> &A) {
    int ph1, ph2, ph3, nl1, nl2, ans;
    ph1 = INT_MIN;
    ph2 = INT_MIN;
    ph3 = INT_MIN;
    nl1 = INT_MAX;
    nl2 = INT_MAX;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] > ph1) {
            ph3 = ph2;
            ph2 = ph1;
            ph1 = A[i];
        }
        else if(A[i] > ph2){
            ph3 = ph2;
            ph2 = A[i];
        }
        else if(A[i] > ph3) ph3 = A[i];
        if(A[i] < nl1) {
            nl2 = nl1;
            nl1 = A[i];
        }
        else if(A[i] < nl2) nl2 = A[i];
    }
    ans = max(ph1 * ph2 * ph3, ph1 * nl1 * nl2);
    return ans;
}