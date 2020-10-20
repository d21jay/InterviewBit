int noOfStudentsRequired(vector<int> &A, int maxPages) {
    int stu = 1;
    int currStuPages = 0;
    for(int i = 0; i < A.size(); i++) {
        if(currStuPages + A[i] > maxPages) {
            stu++;
            currStuPages = 0;
        }
        currStuPages += A[i];
    }
    return stu;
}
int Solution::books(vector<int> &A, int B) {
    if(B>A.size()) return -1;
    int total = 0;
    int max_A = 0;
    for(int i = 0; i < A.size(); i++) {
        total += A[i];
        max_A = A[i] > max_A ? A[i] : max_A;
    }
    //The ans lies between max_A and total;
    int l = max_A;
    int r = total;
    int m = (l+r)/2;
    int ans;
    // we will no check if no of students required to have max m pages is <= B;
    while(l <= r) {
        if(noOfStudentsRequired(A, m) > B) l = m + 1;
        else {
            r = m - 1;
            ans = m;
        }
        m = (l+r)/2;
    }
    return ans;
}
//O(n^2) as with DP approach of soln. (given both B and max_A << n).
//O(n log(sum(A[i]) - max_A)) = O(n log(max_A^(n-1)) = O((n^2)log(max_A)) = O(n^2).
//Hence, saying it O(n logn) O(n log(max_A)) is wrong.
/*if B and max_A are also arbitrarly large:
DP soln : O((n^2)*B)
bs soln : O((n^2)*log(max_A))
*/