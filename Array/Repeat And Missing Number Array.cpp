vector<int> Solution::repeatedNumber(const vector<int> &A) {
    //O(n) space ans is obvious. keep a bool array of size of A.
    //do counting sort.
    long long int sum, ssum;
    sum = 0;
    ssum = 0;
    for(int i = 0; i < A.size(); i++) {
        sum += (A[i] - i - 1);
        ssum += ((long long int) A[i]) * A[i] - ((long long int) i + 1)*(i + 1);
    }
    int repeated, missing;
    // sum = repeated - missing 
    //ssum = repeated^2 - missing^2
    //=> ssum/sum = repeated + missing => an integer.
    ssum /= sum;
    repeated = (int)((ssum + sum)/2);
    missing = (int)((ssum - sum)/2);
    return {repeated, missing};
}
