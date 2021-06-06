int Solution::findMedian(vector<vector<int> > &A) {
int tar = (A.size()*A[0].size()+1)/2;
int x = INT_MAX;
int k, sum, l, r;
int ans = 0;
int aans = 0;
for(int i = 0; i<32; i++){
    sum = 0;
    for(int j = 0; j < A.size(); j++){
          r = A[j].size();
          l = -1;
          k = (r+l)/2;
        while(r>l+1){
          if(A[j][k]<=(ans+x)){
              l = k;
          }
          else if(A[j][k]>(ans+x)){
              r = k;
          }
          k = (r+l)/2;
         }
          sum = sum + r;
    }
    if(sum>tar){
        x = x>>1;
    }
    else if (sum<tar){
        ans = ans + x + 1;
        x = x>>1;
    }
    else{
        ans = ans + x;
        break;
    }
}
bool found = false;
 
for(int j = 0; j < A.size(); j++){
  r = A[j].size();
  l = -1;
  k = (r+l)/2;
  while(r>l+1){
      if (aans == 0 && A[j][k]<ans) aans = A[j][k];
      else if (A[j][k]<ans && A[j][k]>aans) aans = A[j][k];
      if(A[j][k] == ans){
          found = true;
          aans = ans;
          break;
      }
      else if(A[j][k]<ans){
          l = k;
      }
      else if(A[j][k]>ans){
          r = k;
      }
      k = (r+l)/2;
  }
  if(found) break;
}
 
return aans;
}