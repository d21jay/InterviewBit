int Solution::solve(vector<int> &A) {
    int t_odd = 0;
    int t_even = 0;
    for(int i = 0; i < A.size(); i++) {
        if(i%2 == 0) t_even += A[i];
        else t_odd += A[i];
    }
    int count = 0;
    int osum  = 0;
    int esum = 0;
    for(int i = 0; i < A.size(); i++) {
        if(i%2 == 0) {
            if(osum + t_even - esum - A[i] == esum + t_odd - osum) count++;
            esum += A[i];
        }
        else {
            if(osum + t_even - esum == esum + t_odd - osum - A[i]) count++;
            osum += A[i];
        }
    }
    return count;
}