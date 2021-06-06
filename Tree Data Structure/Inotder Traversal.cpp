/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    if(A == NULL) return {};
    stack<pair<TreeNode*, bool>> s;
    s.push({A, false});
    TreeNode* x;
    bool p;
    vector<int> ans;
    while(!s.empty()){
        x = s.top().first;
        p = s.top().second;
        s.pop();
        if(p) ans.push_back(x -> val);
        else{
            if(x -> right != NULL) s.push({x -> right, false});
            s.push({x, true});
            if(x -> left != NULL) s.push({x -> left, false});
        }
    }
    return ans;
}