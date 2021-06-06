nt Solution::lengthOfLastWord(const string A) {
    int flag, ans = 0;
    int n = A.length();
     while(n>0){
         n--;
         if ((ans == 0)&&(A[n]==' ')) continue;
         if(A[n]==' ') break;
         else ans++;
     }
    return ans;
}