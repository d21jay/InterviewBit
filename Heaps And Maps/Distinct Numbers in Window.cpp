vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    unordered_map<int, int> occ;
    B = min(B, (int)A.size());
    for(int i = 0; i < B; i++) {
        if(occ.find(A[i]) == occ.end()) occ.insert({A[i], 1});
        else occ[A[i]]++;
    }
    ans.push_back(occ.size());
    for(int i = B; i < A.size(); i++) {
        if(occ.find(A[i]) == occ.end()) occ.insert({A[i], 1});
        else occ[A[i]]++;
        if(occ[A[i - B]] == 1) occ.erase(A[i - B]);
        else occ[A[i - B]]--;
        ans.push_back(occ.size());
    }
    return ans;
}