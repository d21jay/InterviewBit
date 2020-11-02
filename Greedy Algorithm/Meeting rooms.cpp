bool cc(vector<int> &a, vector<int> &b) {
    //departure before arrival for same time.
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0]; 
}
int Solution::solve(vector<vector<int> > &A) {
    vector<vector<int>> book;
    for(int i = A.size() - 1; i >= 0; i--) {
        book.push_back({A[i][0], 1});
        book.push_back({A[i][1], -1});
        A.pop_back();
    }
    sort(book.begin(), book.end(), cc);
    int booked = 0;
    int ans = 0;
    for(int i = 0; i < book.size(); i++) {
        booked += book[i][1];
        ans = max(booked, ans);
    }
    return ans;
}