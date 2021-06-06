int Solution::evalRPN(vector<string> &A) {
    if(A.size() == 0) return 0;
    stack<int> s;
    int fo, so, x;
    string w;
    for(int i = 0; i < A.size(); i++) {
        w = A[i];
        if(w != "+" && w != "-" && w != "*" && w != "/") x = stoi(w);
        else {
            so = s.top();
            s.pop();
            fo = s.top();
            s.pop();
            if(w == "+") x = so + fo;
            else if(w == "-") x = fo - so;
            else if(w == "*") x = fo * so;
            else if(w == "/") x = fo / so;
        }
        s.push(x);
    }
    return s.top();
}