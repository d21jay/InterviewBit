int Solution::maximumGap(const vector<int> &A) {
    stack<int> minElements;
    //rejects elements not strictly decreasing.
    minElements.push(0);
    for(int i = 1; i < A.size(); i++) {
        if(A[minElements.top()] > A[i]) minElements.push(i);
    }
    int ans = 0;
    for(int i = A.size() - 1; i >= 0; i--) {
        while(!minElements.empty() && A[minElements.top()] <= A[i]) {
            ans = max(ans, i - minElements.top());
            minElements.pop();
        }
    }
    //yeah hard to believe but we only need one stack.
    //could also be done with maxElements by opposite traversal in both loops.
    return ans;
}