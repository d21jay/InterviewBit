void Solution::sortColors(vector<int> &A) {
    long int r, w;
    r = 0;
    w = 0;
    for(int i = 0; i<A.size(); i++){
        if(A[i]==0) r++;
        else if(A[i]==1) w++;
    }
    for(int i = 0; i<r; i++) A[i] = 0;
    for(int i = r; i<r+w; i++) A[i] = 1;
    for(int i = r+w; i<A.size(); i++) A[i] = 2;
}