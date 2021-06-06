/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    if(A == NULL) return;
    vector<vector<TreeLinkNode*>> levels;
    queue<pair<TreeLinkNode*, int>> s;
    TreeLinkNode* x;
    int d;
    s.push({A,0});
    while(!s.empty()){
        d = s.front().second;
        x = s.front().first;
        s.pop();
        if(levels.size() == d) levels.push_back({x});
        else levels[d].push_back(x);
        if(x->left != NULL) s.push({x->left, d + 1});
        if(x->right != NULL) s.push({x->right, d + 1});
    }
    for(int i = 0; i < levels.size(); i++) {
        for(int j = 0; j <levels[i].size() - 1; j++)
            levels[i][j]->next = levels[i][j + 1];
    }
}