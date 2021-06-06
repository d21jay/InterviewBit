/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    if(A == NULL) return {};
    int sum;
    queue<pair<TreeNode*, vector<int>>> q;
    q.push({A, {0}});
    TreeNode* x;
    vector<vector<int>> ans;
    vector<int> t;
    while(!q.empty()) {
        t = q.front().second;
        x = q.front().first;
        t[0] += x->val;
        t.push_back(x->val);
        q.pop();
        if(x->left != NULL) q.push({x->left, t});
        if(x->right != NULL) q.push({x->right, t});
         //root to leaf
        if(t[0] == B && x->left == NULL && x->right == NULL) {
            t.erase(t.begin());
            ans.push_back(t);
        }        
    }
    return ans;
}