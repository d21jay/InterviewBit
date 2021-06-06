int Solution::isPalindrome(string A) {
    transform(A.begin(), A.end(), A.begin(), ::tolower);
    string B = "";
    string s1;
    for(int i = 0; i < A.size(); i++) {
        if((A[i]>= 'a' && A[i] <= 'z') || (A[i]>= '0' && A[i] <= '9')) B.push_back(A[i]);
    }
    s1 = B;
    reverse(s1.begin(), s1.end());
    return (int)(s1 == B);
}