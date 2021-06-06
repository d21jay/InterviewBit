int Solution::braces(string A) {
    //0: open, 1: data
    stack<int> s;
    int x;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == '(') {
            s.push(0);
        }
        else if(A[i] == ')') {
            x = 0;
            while(s.top() == 1) {
                x++;
                s.pop();
            }
            if(x < 3) return 1;
            s.pop();
            s.push(1);
        }
        else {
            s.push(1);
        }
    }
    return 0;
}