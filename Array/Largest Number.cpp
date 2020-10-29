//direct string approach.
//can alternatively be solved using long long int.
bool cc(string &a, string &b){
    return a+b > b+a;
}
string Solution::largestNumber(const vector<int> &A) {
    string ans = "";
    if(A.size() == 0) return ans;
    vector<string> B;
    for(int i = 0; i < A.size(); i++) B.push_back(to_string(A[i]));
    sort(B.begin(), B.end(), cc);
    if(B[0] == "0") return "0";
    for(int i = 0; i < A.size(); i++) ans += B[i];
    return ans;
}