int Solution::candy(vector<int> &A) {
    if(A.size() < 2) return A.size();
    int distributed = 0;
    vector<bool> minima(A.size(), false);
    vector<bool> maxima(A.size(), false);
    vector<int> candies(A.size(), 1);
    //based on non-justice soln: where equal rating neighbour can get different
    //number of candies.
    for(int i = 1; i < A.size() - 1; i++) {
        if(A[i] <= A[i - 1] && A[i] <= A[i + 1]) minima[i] = true;
        if(A[i] >= A[i - 1] && A[i] >= A[i + 1] && !minima[i]) maxima[i] = true;
        //non-justice soln considers inflections as minima.
        //justice soln would keep them intact.
        //(note: also start of inflection is taken maxima here.)
        //justice soln would also take pleatue inflection as maxima
        //and velley inflection as minima.(only true inflection kept intact). 
    }
    if(A[0] <= A[1]) minima[0] = true;
    if(A[A.size() - 1] <= A[A.size() - 2]) minima[A.size() - 1] = true;
    int curr = 1;
    bool on = false;
    for(int i = 0; i < A.size(); i++) {
        if(!minima[i]) curr++;
        else curr = 1;
        if(on) candies[i] = curr;
        if(minima[i]) on = true;
        else if(maxima[i]) on = false;
    }
    on = false;
    for(int i = A.size() - 1; i >= 0; i--) {
        if(!minima[i]) curr++;
        else curr = 1;
        if(on) candies[i] = max(candies[i], curr);
        if(minima[i]) on = true;
        else if(maxima[i]) on = false;
    }
    for(int i = 0; i < A.size(); i++) {
        distributed += candies[i];
    }
    return distributed;
}
//can be eqv done without boolean arrays minima and maxima;
//but it doesn't hurt space complex (already O(n) for int array candies)