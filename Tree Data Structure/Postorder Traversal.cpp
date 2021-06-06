/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    if(A == NULL) return {};
    stack<TreeNode*> qs;
    vector<int> ans;
    qs.push(A);
    TreeNode* x;
    while(!qs.empty()) {
        x = qs.top();
        qs.pop();
        ans.push_back(x -> val);
        if(x -> left != NULL) qs.push(x -> left);
        if(x -> right != NULL) qs.push(x -> right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
//total opp of step opp of preorder traversal