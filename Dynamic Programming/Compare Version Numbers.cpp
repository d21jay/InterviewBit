int Solution::compareVersion(string A, string B) {
    if(A.size() == 0 && B.size() == 0) return 0;
    if(A == B) return 0; // not required but ok.
    string x = A, y = B;
    string s1 = "", s2 = "";
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == '.') {
            x = A.substr(0, i);
            s1 = A.substr(i + 1, A.size() - i - 1);
            break;
        }
    }
    for(int i = 0; i < B.size(); i++) {
        if(B[i] == '.') {
            y = B.substr(0, i);
            s2 = B.substr(i + 1, B.size() - i - 1);
            break;
        }
    }
    string s = "";
    if(x.size() > y.size()) {
        for(int i = 0; i < x.size() - y.size(); i++) s.push_back('0');
        y = s + y;
    }
    if(x.size() < y.size()) {
        for(int i = 0; i < y.size() - x.size(); i++) s.push_back('0');
        x = s + x;
    }
    if(x > y) return 1;
    if(y > x) return -1;
    return compareVersion(s1, s2);
}