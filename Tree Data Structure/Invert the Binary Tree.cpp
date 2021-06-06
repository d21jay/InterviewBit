/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* A) {
    if(A == NULL) return A;
    TreeNode* x;
    TreeNode* z;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()) {
        x = q.front();
        q.pop();
        if(x -> left != NULL) q.push(x -> left);
        if(x -> right != NULL) q.push(x -> right);
        z = x -> left;
        x -> left = x -> right;
        x -> right = z;
    }
    return A;
}