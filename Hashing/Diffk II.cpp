int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_set<int> num;
    for(int i = 0; i < A.size(); i++) {
        if(num.find(A[i] + B) != num.end()) return 1;
        else if(num.find(A[i] - B) != num.end()) return 1;
        num.insert(A[i]);
    }
    return 0;
}