/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    if(A == NULL) return ans;
    queue<pair<TreeNode*, int>> q;
    q.push({A, 0});
    int d;
    while(!q.empty()){
        A = q.front().first;
        d = q.front().second;
        q.pop();
        if(d == ans.size()) ans.push_back({A -> val});
        else ans[d].push_back(A -> val);
        if(A -> left != NULL) q.push({A -> left, d + 1});
        if(A -> right != NULL) q.push({A -> right, d + 1});
    }
    for(int i = 0; i <= d; i++) {
        if(i%2) reverse(ans[i].begin(), ans[i].end());
    }
    return ans;
}