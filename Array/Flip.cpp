vector<int> Solution::flip(string A) {
    int gl = 0;
    int gr = 0;
    int gc = 0;
    int count = -1;
    int l, r;
    for(int i = 0; i< A.size(); i++) {
        //for lexiographic soln count < 0 and not count == 0
        if(count < 0){
            if(A[i] == '0') {
                l = i + 1;
                r = i + 1;
                count = 1;
            }
        }
        else{
            if(A[i] == '0') count++;
            else count--;
            r++;
        }
        if(count > gc) {
            gc = count;
            gl = l;
            gr = r;
        }
    }
    vector<int> ans;
    if(gc > 0){
        ans.push_back(gl);
        ans.push_back(gr);
    }
    return ans;
}