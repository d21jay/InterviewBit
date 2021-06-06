int Solution::threeSumClosest(vector<int> &A, int B) {
    int ans = 0;
    if(A.size()<3) return ans;
    ans = A[0]+A[1]+A[A.size()-1];
    sort(A.begin(),A.end());
    for (int i = 0; i<A.size()-2; i++){
        if(i!=0 && A[i]==A[i-1]) continue;
        int j = i+1;
        int k = A.size()-1;
        while(j<k){
            if(A[i]+A[j]+A[k]>B){
                if(abs(A[i]+A[j]+A[k]-B)<abs(ans-B))
                ans = A[i]+A[j]+A[k];
                k--;
            }
            else if(A[i]+A[j]+A[k]<B){
                if(abs(A[i]+A[j]+A[k]-B)<abs(ans-B))
                ans = A[i]+A[j]+A[k];
                j++;
            }
            else{
                return B;
            }
        }
    }
    return ans;
}