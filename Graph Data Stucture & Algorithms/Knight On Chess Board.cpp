int Solution::knight(int A, int B, int C, int D, int E, int F) {
    //if(C == D && E == F) return 0;
    vector<vector<int>> mark(A, vector<int>(B));
    mark[C-1][D-1] = 1;
    queue<pair<int, int>> q;
    q.push({C, D});
    int i, j, d, x, y;
    while(!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        d = mark[i-1][j-1];
        if(i == E && j == F) return d -1;
        x = i - 1; y = j - 2;
        if(x>0 && y > 0 && mark[x-1][y-1] == 0) {
            mark[x-1][y-1] = d + 1;
            q.push({x,y});
        }
        x = i - 2; y = j - 1;
        if(x>0 && y > 0 && mark[x-1][y-1] == 0) {
            mark[x-1][y-1] = d + 1;
            q.push({x,y});
        }
        x = i + 1; y = j - 2;
        if(x<=A && y > 0 && mark[x-1][y-1] == 0) {
            mark[x-1][y-1] = d + 1;
            q.push({x,y});
        }
        x = i + 2; y = j - 1;
        if(x<=A && y > 0 && mark[x-1][y-1] == 0) {
            mark[x-1][y-1] = d + 1;
            q.push({x,y});
        }
        x = i + 1; y = j + 2;
        if(x<=A && y <=B && mark[x-1][y-1] == 0) {
            mark[x-1][y-1] = d + 1;
            q.push({x,y});
        }
        x = i + 2; y = j + 1;
        if(x <= A && y <= B && mark[x-1][y-1] == 0) {
            mark[x-1][y-1] = d + 1;
            q.push({x,y});
        }
        x = i - 1; y = j + 2;
        if(x>0 && y <= B && mark[x-1][y-1] == 0) {
            mark[x-1][y-1] = d + 1;
            q.push({x,y});
        }
        x = i - 2; y = j + 1;
        if(x>0 && y <= B && mark[x-1][y-1] == 0) {
            mark[x-1][y-1] = d + 1;
            q.push({x,y});
        }
    }
    return -1;
}
//can compress code, but ok.