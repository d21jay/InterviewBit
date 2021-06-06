unsigned int Solution::reverse(unsigned int A) {
    unsigned int ans = 0;
    for(int i = 0; i<32; i++){
        ans = ans*2;
        if(A%2){
            ans++;
        }
        A/=2;
    }
    return ans;
}