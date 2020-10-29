int Solution::solve(vector<string> &A) {
    if(A.size() < 3) return 0;
    double min1, min2, min3, thres = 1;
    int i1, i2, i3;
    i1 = -1; i2 = -1; i3 = -1;
    thres /= 3;
    min1 = INT_MAX;
    min2 = INT_MAX;
    min3 = INT_MAX;
    double x;
    for(int i = 0; i < A.size(); i++) {
        x = stod(A[i]);
        if(x > thres){
            if(x < min1) {
                min1 = x;
                i1 = i;   
            }
        }
    }
    thres = (1 - min1) / 2;
    for(int i = 0; i < A.size(); i++) {
        x = stod(A[i]);
        if(x > thres && i != i1){
            if(x < min2) {
                min2 = x;
                i2 = i;   
            }
        }
    }
    thres = (1 - min1 - min2) / 2;
    for(int i = 0; i < A.size(); i++) {
        x = stod(A[i]);
        if(x > thres && i != i1 && i != i2){
            if(x < min3) {
                min3 = x;
                i3 = i;   
            }
        }
    }
    cout<<min1<<'-';cout<<min2<<'-';cout<<min3<<'-';
    if(i1 == -1 || i2 == -1 || i3 == -1) return 0;
    else if(min1 + min2 + min3 < 2) return 1;
    else return 0;
}