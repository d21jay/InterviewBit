
int Solution::maximumGap(const vector<int> &A) {
    //converting to #PegionHole problem
    if(A.size()<2) return 0;
    vector<int> B(A.size(), -1);
    vector<int> C(A.size(), -1);
    int currMin, currMax;
    int n = A.size();
    currMin = A[0];
    currMax = A[0];
    int lrdiff = 0;
    for(int i = 1; i < n; i++) {
        currMin = currMin < A[i] ? currMin : A[i];
        currMax = currMax > A[i] ? currMax : A[i];
    }
    lrdiff = currMax - currMin;
    if (lrdiff == 0) return 0;
    
    // now lets make n-1 equal sized buckets on real line.
    // currMin--x1--x2-- ...--currMax. bucket style : " [ ) ".
    // now fitting n-2 items in n-1 buckets makes it pegion hole.
    // so, there exists diff > bucket size b/w two sorted elems.
    // so we don't need to look diff of elems inside same bucket. 
    // They thogether become Super-elems with a min and max val.
    // And these Super-elems are by default non-overlapping and sorted.
    // soln will be equivalent to radix/counting sort if we name buckets 0, 1, 2, 3...
    int buckId;
    for(int i = 0; i < n; i++){
        // B will contain min of bucket i. C will contain max of bucket i.
        buckId = (int) ((((long long int)(A[i]-currMin))*(n-1))/lrdiff);
        //index n-1 will only contain currMax for both B nd C;
        //only index 0 to n-2 are the buckets. n-1 index is just for closure mark
        //of buckets having style [ ) on real line.
        if(B[buckId] == -1) B[buckId] = A[i];
        else B[buckId] = B[buckId] < A[i] ? B[buckId] : A[i];
        if(C[buckId] == -1) C[buckId] = A[i];
        else C[buckId] = C[buckId] > A[i] ? C[buckId] : A[i];
        
    }
    int ans = 0;
    int i = 0; // going over C.
    int j = 1; // going over B
    while(i < n - 1 && j < n){
        while(B[j] == -1) j++;
        //C[0] can't be -1 as it is >= currMin. So is true for B[n-1] = currMax;
        ans = (B[j] - C[i]) > ans ? (B[j] - C[i]) : ans;
        i = j;
        j++;
    }
    
    //-----------------------------------------------
    //:interviewBit platform has some strange problem.\n;
    //if submission sometimes gives a particular wrong ans (not random)
    //and custom input always gives right ans,
    //and one don't have any global variable or any undeclared/uninit variable:
    // and one is absolutely sure there can't be anything wrong:
    // then try adding some 'totaly unrelated' dead code!!! Might work.
    // somehow (on particular rare case combn of one's code with problrm) their driver fn
    // seems to get affected by the time taken by soln func to return;
    //-----------------------------------------------
    return ans;
}
