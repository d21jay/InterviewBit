/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::maxDepth(TreeNode* A) {
    if(A == NULL) return 0;
    int d;
    queue<pair<TreeNode*, int>> q;
    q.push({A, 1});
    TreeNode* x;
    while(!q.empty()) {
        d = q.front().second;
        x = q.front().first;
        q.pop();
        if(x->left != NULL) q.push({x->left, d + 1});
        if(x->right != NULL) q.push({x->right, d + 1});
    }
    return d;
}