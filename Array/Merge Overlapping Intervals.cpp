/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cc(Interval &a, Interval &b) {
    if(a.start < b.start) return true;
    else if(b.start < a.start) return false;
    else if(a.end < b.end) return true;
    else return false;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> B;
    sort(A.begin(), A.end(), cc);
    if(A.size()>0) {
        B.push_back(A[0]);
        for(int i = 1; i<A.size(); i++) {
            if(B[B.size() - 1].end >= A[i].start) {
                B[B.size() - 1].end = A[i].end > B[B.size()-1].end ? A[i].end : B[B.size()-1].end;
            }
            else B.push_back(A[i]);
        }
    }
    return B;
}