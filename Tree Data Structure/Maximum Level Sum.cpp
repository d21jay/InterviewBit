/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A) {
    if(A == NULL) return NULL;
    vector<int> sums;
    queue<pair<TreeNode*, int>> q;
    q.push({A,0});
    TreeNode* x;
    int d;
    int sum = A->val;
    while(!q.empty()){
        d = q.front().second;
        x = q.front().first;
        q.pop();
        if(d == sums.size()) sums.push_back(x->val);
        else sums[d] += x->val;
        if(x->left != NULL) q.push({x->left, d + 1});
        if(x->right != NULL) q.push({x->right, d + 1});
    }
    for(int i = 1; i < sums.size(); i++) sum = max(sum, sums[i]);
    return sum;
}