vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> ans;
    int i, j, k, n, a, b, c;
    i = -1;
    j = -1;
    k = -1;
    a = 1;
    b = 1;
    c = 1;
    for(int l = 0; l < D; l++) {
        if(i != -1) a = ans[i]; 
        if(j != -1) b = ans[j];
        if(k != -1) c = ans[k];
        n = min(a * A, min(b * B, c * C));
        ans.push_back(n);
        if(n == a * A) i++;
        if(n == b * B) j++;
        if(n == c * C) k++;
    }
    return ans;
}