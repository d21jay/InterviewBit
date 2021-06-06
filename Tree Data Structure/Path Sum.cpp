/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode* A, int B) {
    if(A == NULL) return 0;
    int sum;
    queue<pair<TreeNode*, int>> q;
    q.push({A, 0});
    TreeNode* x;
    while(!q.empty()) {
        sum = q.front().second;
        x = q.front().first;
        sum += x->val;
        //root to leaf
        if(sum == B && x->left == NULL && x->right == NULL) return 1;
        q.pop();
        if(x->left != NULL) q.push({x->left, sum});
        if(x->right != NULL) q.push({x->right, sum});
    }
    return 0;
}