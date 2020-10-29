int Solution::solve(vector<int> &A, int B) {
    int count = 0;
    bool np;
    for(int i = 0; i < A.size(); i++) {
        np = true;
        for(int j = i + B - 1; j > i - B; j--) {
            if(j >= 0 && j < A.size() && A[j] == 1) {
                i = j + B - 1;
                count++;
                np = false;
                break;
            }
        }
        if(np) return -1;
    }
    return count;
}