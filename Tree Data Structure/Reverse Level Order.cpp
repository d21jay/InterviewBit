/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    if(A == NULL) return {};
    vector<int> ans;
    queue<TreeNode*> s;
    TreeNode* x;
    s.push(A);
    while(!s.empty()){
        x = s.front();
        s.pop();
        ans.push_back(x->val);
        //reverse
        if(x->right != NULL) s.push(x->right);
        if(x->left != NULL) s.push(x->left);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}