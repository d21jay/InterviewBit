int Solution::isValidSudoku(const vector<string> &A) {
    vector<vector<bool>> rows;
    vector<vector<bool>> cols;
    vector<vector<bool>> blocks;
    vector<bool> temp(9, false);
    int x, b;
    string s;
    for(int i = 0; i < 9; i++) {
        rows.push_back(temp);
        cols.push_back(temp);
        blocks.push_back(temp);
    }
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(A[i][j] == '.') continue;
            s = A[i][j];
            x = stoi(s) - 1;
            b = (i/3)*3 + j/3;
            if(rows[i][x] || cols[j][x] || blocks[b][x]) return 0;
            rows[i][x] = true;
            cols[j][x] = true;
            blocks[b][x] = true;
        }
    }
    return 1;
}