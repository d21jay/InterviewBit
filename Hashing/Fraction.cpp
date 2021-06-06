string Solution::fractionToDecimal(int A, int B) {
    string bd, ad = "";
    long long int a = A;
    long long int b = B;
    long long int k = a/b;
    bd = to_string(k);
    a = a - k*b;
    if(a == 0) return bd;
    if(b < 0) {
        a = -1 * a;
        b = -1 * b;
    }
    if(k == 0 && a < 0) bd = "-" + bd;
    if(a < 0) a = -1 * a;
    unordered_map<int, int> rem;
    int i = 0;
    while(true){
        if(a == 0) break;
        if(rem.find(a) == rem.end()) rem.insert({a, i});
        else {
            string s = ad.substr(rem[a]);
            ad = ad.substr(0, rem[a]);
            ad = ad + "(" + s + ")";
            break;
        }
        a *= 10;
        k = a/b;
        a = a - k*b;
        ad += to_string(k);
        i++;
    }
    return bd + "." + ad;
}