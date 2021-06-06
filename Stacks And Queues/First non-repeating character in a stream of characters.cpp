string Solution::solve(string A) {
    //too many ways to solve, lets use queue
    vector<int> count(26, 0);
    queue<int> q;
    string b = "";
    for(int i = 0; i < A.size(); i++){
        q.push(A[i]);
        count[A[i] - 'a']++;
        while(!q.empty() && count[q.front() - 'a'] > 1) q.pop();
        if(q.empty()) b += "#";
        else b.push_back(q.front());
    }
    return b;
}