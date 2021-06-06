vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int>> ans;
    if(A.size()<3) return ans;
    sort(A.begin(),A.end());
    for (int i = 0; i<A.size()-2; i++){
        if(i!=0 && A[i]==A[i-1]) continue;
        int j = i+1;
        int k = A.size()-1;
        while(j<k){
            if(A[i]+A[j]+A[k]>0) k--;
            else if(A[i]+A[j]+A[k]<0) j++;
            else{
                vector<int> temp = {A[i],A[j],A[k]};
                k--;
                j++;
                if(ans.size()==0) ans.push_back(temp);
                else if(temp[0]!=ans[ans.size()-1][0]||temp[1]!=ans[ans.size()-1][1]||
                temp[2]!=ans[ans.size()-1][2]) ans.push_back(temp);
            }
        }
    }
    return ans;
}