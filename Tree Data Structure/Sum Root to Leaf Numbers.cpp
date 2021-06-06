/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::sumNumbers(TreeNode* A) {
    if(A == NULL) return 0;
    int sum;
    queue<pair<TreeNode*, int>> q;
    q.push({A, 0});
    TreeNode* x;
    int ans = 0;
    int mod = 1003;
    while(!q.empty()) {
        sum = q.front().second;
        x = q.front().first;
        sum = (sum*10 + x->val) % mod;
        //root to leaf
        if(x->left == NULL && x->right == NULL) ans = (ans + sum) % mod;
        q.pop();
        if(x->left != NULL) q.push({x->left, sum});
        if(x->right != NULL) q.push({x->right, sum});
    }
    return ans;
}