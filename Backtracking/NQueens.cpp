vector<vector<string>> ans;
vector<bool> c, d, ad;
string prot;
void engine(vector<string> &tmp, int A){
    int rs = tmp.size();
    if(rs == A) {
        ans.push_back(tmp);
        return;
    }
    string x;
    for(int i = 0; i < A; i++){
        if(!c[i] && !d[rs - i + A - 1] && !ad[rs + i]) {
            x = prot;
            x[i] = 'Q';
            tmp.push_back(x);
            c[i] = true;
            d[rs - i + A - 1] = true;
            ad[rs + i] = true;
            engine(tmp, A);
            tmp.pop_back();
            c[i] = false;
            d[rs - i + A - 1] = false;
            ad[rs + i] = false;
        }
    }
    
}
vector<vector<string> > Solution::solveNQueens(int A) {
    ans = *(new vector<vector<string>>);
    c = *(new vector<bool>(A, false));
    d = *(new vector<bool>(2*A-1, false));
    ad = *(new vector<bool>(2*A-1, false));
    prot = *(new string(A, '.'));
    vector<string> tmp;
    engine(tmp, A);
    return ans;
}