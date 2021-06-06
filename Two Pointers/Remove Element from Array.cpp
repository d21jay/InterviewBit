int Solution::removeElement(vector<int> &A, int B) {
    int count = A.size();
    int t = 0;
    for(int i = 0; i<A.size(); i++){
        if(A[i]==B) count--;
        else{
            A[t] = A[i];
            t++;
        }
    }
    return count;
}