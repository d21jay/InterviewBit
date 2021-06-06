string Solution::getPermutation(int A, int B) {
    vector<int> holder;
    string ans = "";
    for(int i = 0; i < A; i++){
        holder.push_back(i+1);
    }
    vector<int> fact(A, 1);
    vector<int> times(A, 0);
    B--;
    int x = 1;
    int y;
    int i = 1;
    while(x <= B) {
        if(i == A) {
            B = B % fact[i - 1];
            break;
        }
        x = fact[i - 1] * (i + 1);
        fact[i] = x;
        i++;
    }
    i--;
    while(B > 0) {
       times[A - 1 - i] = B/fact[i - 1];
       B = B%fact[i - 1];
       i--;
    }
    for(int i = 0; i < A; i++) {
        y = holder[i + times[i]];
        for(int j = i + times[i]; j >= i + 1; j--){
            holder[j] = holder[j - 1];
        }
        holder[i] = y;
    }
    
    for(int i = 0; i < A; i++) {
        ans += to_string(holder[i]);
    }
    return ans;
}