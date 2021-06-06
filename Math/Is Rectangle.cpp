int Solution::solve(int A, int B, int C, int D) {
    vector<int> abcd = {A, B, C, D};
    sort(abcd.begin(), abcd.end());
    if(abcd[0] == abcd[1] && abcd[2] == abcd[3]) return 1;
    return 0;
}