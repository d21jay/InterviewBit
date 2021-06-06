int Solution::solve(string A) {
    //don't haste on finding a mismatch. you don't know the future. so can not chose
    //only one of the option of removing left or right. ex: baeacaeb or beacaeab
    string s = "";
    string s1;
    string s2 = "", s3 = "";
    int l = 0;
    int r = A.size() - 1;
    while(l < r) {
        if(A[l] != A[r]) break;
        l++;
        r--;
    }
    if(l > r) return 0; //even palindrome;
    for(int i = l + 1; i < r; i++) s.push_back(A[i]);
    s1 = s;
    reverse(s1.begin(), s1.end());
    s2.push_back(A[l]);
    s3.push_back(A[r]);
    s2 += s;
    s3 += s1;
    s.push_back(A[r]);
    s1.push_back(A[l]);
    if(s == s3) return 1;
    if(s1 == s2) return 1;
    return 0;
}