/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    queue<pair<TreeNode*, int>> nodes;
    if(A == NULL) return {};
    nodes.push({A, 0});
    vector<vector<int>> ans;
    while(!nodes.empty()){
        pair<TreeNode*, int> pair= nodes.front();
        nodes.pop();
        if(pair.second == ans.size()) ans.push_back({pair.first->val});
        else ans[pair.second].push_back(pair.first->val);
        if(pair.first->left != NULL) nodes.push({pair.first->left, pair.second + 1});
        if(pair.first->right != NULL) nodes.push({pair.first->right, pair.second + 1});
    }
    return ans;
}