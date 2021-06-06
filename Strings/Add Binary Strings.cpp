string Solution::addBinary(string A, string B) {
    string ans = "";
    int n = min(A.size(), B.size());
    int carry = 0;
    int x, y, z;
    for(int i = 1; i <= n; i++) {
        x = A[A.size() - i] - '0';
        y = B[B.size() - i] - '0';
        z = x + y + carry;
        if(z > 1) carry = 1;
        else carry = 0;
        if(z%2 == 1) ans.push_back('1');
        else ans.push_back('0');
    }
    if(A.size() > B.size()) B = A;
    for(int i = B.size() - n - 1; i >= 0; i--) {
        x = B[i] - '0';
        z = x + carry;
        if(z > 1) carry = 1;
        else carry = 0;
        if(z%2 == 1) ans.push_back('1');
        else ans.push_back('0');
    }
    if(carry == 1) ans.push_back('1');
    reverse(ans.begin(), ans.end());
    return ans;
}