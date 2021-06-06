/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    if(A == NULL) return {};
    stack<TreeNode*> sq;
    sq.push(A);
    vector<int> ans;
    TreeNode* x;
    while(!sq.empty()){
        x = sq.top();
        sq.pop();
        ans.push_back(x -> val);
        if(x -> right != NULL) sq.push(x -> right);
        if(x -> left != NULL) sq.push(x -> left);
    }
    return ans;
}