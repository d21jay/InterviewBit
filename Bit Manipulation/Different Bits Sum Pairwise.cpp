int Solution::cntBits(vector<int> &A) {
    int ans = 0;  
    for (int i = 0; i < 32; i++) 
    { 
        int count = 0; 
        for (int j = 0; j < A.size(); j++) 
            if ( (A[j] & (1 << i)) ) 
                count++; 
        ans = (ans + (count * (A.size() - count) * 2)) % 1000000007; 
    } 
    return ans; 
}