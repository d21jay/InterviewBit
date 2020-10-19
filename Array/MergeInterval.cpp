/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> B;
    if(newInterval.start > newInterval.end) swap(newInterval.start, newInterval.end);
    if(intervals.size() == 0) B.push_back(newInterval);
    else {
        int j = 0;
        if(intervals[0].start<newInterval.start) {
            B.push_back(intervals[0]);
            j = 1;
        }
        else B.push_back(newInterval);
        for(int i = j; i<intervals.size(); i++) {
            if(j == 1 && newInterval.start < intervals[i].start) {
                if(newInterval.start <= B[B.size() - 1].end) {
                    if(newInterval.end > B[B.size() - 1].end)
                        B[B.size() - 1].end = newInterval.end; 
                }
                else {
                    B.push_back(newInterval);
                }
                j = 0;
                i--;
            }
            else {
                if(intervals[i].start <= B[B.size() - 1].end) {
                    if(intervals[i].end > B[B.size() - 1].end)
                        B[B.size() - 1].end = intervals[i].end; 
                }
                else {
                    B.push_back(intervals[i]);
                }
            }
        }
        if(j == 1) {
             if(newInterval.start <= B[B.size() - 1].end) {
                    if(newInterval.end > B[B.size() - 1].end)
                        B[B.size() - 1].end = newInterval.end; 
                }
                else {
                    B.push_back(newInterval);
                }
        }
    }
    return B;
}
//O(n)