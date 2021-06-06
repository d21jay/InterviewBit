int Solution::removeDuplicates(vector<int> &A) {  
    if(A.size()<3) return A.size();
    int* x= &(A[0]);
    int* y= &(A[1]);
    int* t= &(A[2]);
    int count=2;
    int i=0;
    for(i=1;i<A.size()-1;i++){
        if(*x != *y || *y != *t){
            A[count]= *t;
            count++;
            x++;
            y++;
        }
        t= &(A[i+2]);
    }
    return count;
}