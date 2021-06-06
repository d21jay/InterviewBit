/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void findEngine(TreeNode* x, vector<int> &acs, int tar, bool &found) {
    acs.push_back(x -> val);
    if(x -> val == tar) {
        found = true;
        return;
    }
    if(x -> left != NULL) {
        findEngine(x -> left, acs, tar, found);
        if(found) return;
    }
    if(x -> right != NULL) {
        findEngine(x -> right, acs, tar, found);
        if(found) return;
    }
    acs.pop_back();
}
int Solution::lca(TreeNode* A, int B, int C) {
    if(A == NULL) return -1;
    bool found = false;
    vector<int> b, c;
    findEngine(A, b, B, found);
    if(!found) return -1;
    found = false;
    findEngine(A, c, C, found);
    if(!found) return -1;
    int x = b[0];
    for(int i = 1; (i < b.size() && i < c.size()); i++) {
        if(b[i] != c[i]) break;
        x = b[i];
    }
    return x;
}