/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans;
int maxLinear(TreeNode* A) {
    int lval = 0;
    int rval = 0;
    if(A -> left != NULL) lval = max(0, maxLinear(A -> left));
    if(A -> right != NULL) rval = max(0, maxLinear(A -> right));
    
    ans = max(ans, lval + rval + A -> val);
    return max(lval, rval) + A->val;
}
int Solution::maxPathSum(TreeNode* A) {
    if(A == NULL) return 0;
    ans = A->val;
    maxLinear(A);
    return ans;
}