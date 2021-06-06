int Solution::largestRectangleArea(vector<int> &A) {
    A.push_back(0);
    int ans = 0;
    stack<int> s;
    stack<int> r;
    int w;
    for(int i = 0 ; i < A.size(); i++) {
        w = i;
        while(!s.empty() && A[s.top()] > A[i]) {
            ans = max(ans, A[i] * (i - r.top() + 1));
            ans = max(ans, A[s.top()] *  (i - r.top()));
            w = r.top();
            s.pop();
            r.pop();
        }
        r.push(w);
        s.push(i);
    }
    return ans;
}