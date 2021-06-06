int Solution::solve(vector<int> &A, int B) {
    priority_queue<int> pq;
    int ans = 0;
    for(int i = 0; i < A.size(); i++) {
        pq.push(A[i]);
    }
    int x;
    for(int i = 0; i < B; i++) {
        x = pq.top();
        ans += x;
        x--;
        pq.pop();
        pq.push(x);
    }
    return ans;
}