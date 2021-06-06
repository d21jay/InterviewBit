vector<int> Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end(), greater<int>());
    while(A.size() > B) A.pop_back();
    return A;
}