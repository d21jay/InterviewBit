int Solution::trap(const vector<int> &A) {
    stack<int> s;
    int ans = 0;
    int b;
    for(int i = 0; i < A.size(); i++) {
        b = 0;
        while(!s.empty() && A[s.top()] <= A[i]) {
            ans += ((A[s.top()] - b) * (i - s.top() - 1));
            b = A[s.top()];
            s.pop();
        }
        if(!s.empty()) {
            ans += ((A[i] - b) * (i - s.top() - 1));
        }
        s.push(i);
    }
    return ans;
}