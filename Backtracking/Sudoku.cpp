bool found;
void engine(vector<vector<char>> &A, vector<vector<bool>> &rows, vector<vector<bool>> &cols,
            vector<vector<bool>> &blocks, int i, int j) {
    if(j == 9) {
        i++;
        j = 0;
    }
    if(i == 9) {
        found = true;
        return;
    }
    int x = (i/3)*3 + (j/3);
    if(A[i][j] == '.') {
        for(int k = 0; k < 9; k++) {
            if(rows[i][k] || cols[j][k] || blocks[x][k]) continue;
            else {
                rows[i][k] = true;
                cols[j][k] = true;
                blocks[x][k] = true;
                A[i][j] = '1' + k;
                engine(A, rows, cols, blocks, i, j + 1);
                if(!found) {
                    rows[i][k] = false;
                    cols[j][k] = false;
                    blocks[x][k] = false;
                    A[i][j] = '.';
                }
                else return;
            }
        }
    }
    else {
        engine(A, rows, cols, blocks, i, j + 1);
    }
}
void Solution::solveSudoku(vector<vector<char> > &A) {
    found = false;
    vector<vector<bool>> rows, cols, blocks;
    vector<bool> temp(9, false);
    for(int i = 0; i < 9; i++) {
        rows.push_back(temp);
        cols.push_back(temp);
        blocks.push_back(temp);
    }
    int x, val;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            x = (i/3)*3 + j/3;
            if(A[i][j] != '.') {
                val = A[i][j] - '1';
                rows[i][val] = true;
                cols[j][val] = true;
                blocks[x][val] = true;
            }
        }
    }
    engine(A, rows, cols, blocks, 0, 0);
}