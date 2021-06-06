int Solution::isPower(int A) {
    unordered_map<int, int> pows;
    int s = 2;
    int c = 0;
    while(A >= s){
        if(A % s == 0){
            c = 0;
            while(A % s == 0) {
                c++;
                A /= s;
            }
            pows.insert({s, c});
        }
        else s++;
    }
    for(auto itr = pows.begin(); itr != pows.end(); itr++) {
        if(itr->second == 1) return false;
    }
    return true;
}

/* alternate solution:
int Solution::isPower(int A) {
    int n = sqrt(A);
    int i;
    double curr;
    if (A==1) return 1;
    for(i=2; i<=n;i++){
        curr = log10 (A)/log10 (i);
        if ((int)curr == curr) return 1;
    }
    return 0;
}
*/