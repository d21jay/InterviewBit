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
    queue<TreeNode*> q;
    TreeNode* x;
    vector<int> ans;
    q.push(A);
    while(!q.empty()) {
        x = q.front();
        q.pop();
        while(x != NULL) {
            ans.push_back(x -> val);
            if(x -> left != NULL) q.push(x -> left);
            x = x -> right;
        }
    }
    return ans;
}