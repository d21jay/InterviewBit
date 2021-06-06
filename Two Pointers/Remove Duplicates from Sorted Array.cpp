int Solution::removeDuplicates(vector<int> &A) {
    if(A.size()==0) return 0;
    int ans = 1;
    int* x = &A[0];
    int* y = &A[1];
    for (int i = 1; i<A.size(); i++){
        if(*x != *y){
            A[ans] = *y;
            x++;
            ans++;
        }
        y = & A[i+1];
    }
    return ans;
}