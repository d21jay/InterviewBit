vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int, int> ind;
    for(int i = 0; i < A.size(); i++){
        if(ind.find(B - A[i]) != ind.end()) return {ind[B - A[i]], i + 1};
        if(ind.find(A[i]) == ind.end()) ind.insert({A[i], i + 1});
    }
    return {};
}