int Solution::repeatedNumber(const vector<int> &A) {
    int ans = -1;
    int count1, count2;
    int a = 0; int b = -1;
    count1 = 0;
    count2 = 0;
    for(int i = 0; i<A.size(); i++){
            if(count1 == 0 && A[i]!=b){
                a = A[i];
                count1 = 1;
            }
            else if(count2 == 0 && A[i]!=a){
                b = A[i];
                count2 = 1;
            }
            else if(A[i] == a){
                count1++;
            }
            else if(A[i] == b){
                count2++;
            }
            else {
                count1--;
                count2--;
            }
    }
    count1 = 0;
    count2 = 0;
    for(int i = 0; i<A.size(); i++){
        if(A[i] == a) count1++;
        else if(A[i] == b) count2++;
    }
    if(count1 > A.size()/3) ans = a;
    else if(count2 > A.size()/3) ans = b;
    return ans;
}
