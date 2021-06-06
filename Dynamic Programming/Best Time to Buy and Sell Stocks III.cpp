int Solution::maxProfit(const vector<int> &A) {
    //atmost B transactions.
    if(A.size() == 0) return 0;
    vector<vector<int>> transactions(2, vector<int>(A.size()));
    int minv = A[0];
    for(int i = 1; i < A.size(); i++) {
        minv = min(minv, A[i]);
        transactions[0][i] = max(transactions[0][i - 1], A[i] - minv);
    }
    int max_till = -A[0];
    for(int j = 1; j < A.size(); j++) {
        transactions[1][j] = max(transactions[1][j - 1], transactions[0][j]);
        max_till = max(max_till, transactions[0][j - 1] - A[j - 1]);
        transactions[1][j] = max(transactions[1][j], max_till + A[j]);
    }
    return transactions[1][A.size() - 1];
}