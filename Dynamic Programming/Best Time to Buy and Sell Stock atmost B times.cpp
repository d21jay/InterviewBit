int Solution::solve(vector<int> &A, int B) {
    //atmost transactions.
    if(A.size() == 0 || B < 1) return 0;
    B = min((int)A.size()/2, B);
    //lets do O(nB) now;
    vector<vector<int>> transactions(B, vector<int>(A.size()));
    int minv = A[0];
    for(int i = 1; i < A.size(); i++) {
        minv = min(minv, A[i]);
        transactions[0][i] = max(transactions[0][i - 1], A[i] - minv);
    }
    int transaction_at_buy; //Hero step;
    for(int i = 1; i < B; i++) {
        transaction_at_buy = -A[0];
        //bought day1 stock;
        for(int j = 1; j < A.size(); j++) {
            transaction_at_buy = max(transaction_at_buy, transactions[i - 1][j - 1] - A[j - 1]);
            //if didn't bought last day, I already have transaction_at_buy.
            transactions[i][j] = max(transactions[i][j - 1], transactions[i - 1][j]);
            /*
            for(int k = 0; k < j; k++) {
                transactions[i][j] = max(transactions[i][j],
                                    transactions[i - 1][k] + A[j] - A[k]);
            } it is O(n^2B); worked though. this loop get translated in transaction_at_buy.
            */
            transactions[i][j] = max(transactions[i][j], transaction_at_buy + A[j]);
            //basically in the ith transaction turn, calculated buying price in 1 step for
            //any day.
        }
    }
    return transactions[B  - 1][A.size() - 1];
}