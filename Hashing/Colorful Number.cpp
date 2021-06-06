int Solution::colorful(int A) {
    vector<int> digits;
    unordered_set<int> uset;
    int x;
    while(A > 0){
        digits.push_back(A%10);
        A /= 10;
    }
    for(int i = 0; i < digits.size(); i++) {
        x = 1;
        for(int j = i; j < digits.size(); j++) {
            //always less then INT_MAx
            x *= digits[j];
            if(uset.find(x) != uset.end()) return 0;
            uset.insert(x);
        }
    }
    return 1;
}