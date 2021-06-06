int Solution::maximalRectangle(vector<vector<int> > &A) {
    int ans = 0;
    for(int i = 1; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            if(A[i][j] == 1) A[i][j] += A[i - 1][j];
        }
    }
    //converted into histograms;
    stack<int> s;
    int top;
    int len;
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            while(!s.empty() && A[i][s.top()] > A[i][j]) {
                top = s.top();
                s.pop();
                if(!s.empty()) len = j - s.top() - 1;
                else len = j;
                ans = max(ans, A[i][top] * len);
            }
            s.push(j);
        }
        while(!s.empty()) {
            top = s.top();
            s.pop();
            if(!s.empty()) len = A[0].size() - s.top() - 1;
            else len = A[0].size();
            ans = max(ans, A[i][top] * len);
        }
    }
    return ans;   
}