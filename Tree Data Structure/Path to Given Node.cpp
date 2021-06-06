/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    //dfs is natural but bfs has slightly better space req in one directional tree.
    if(A == NULL) return {};
    unordered_map<int, int> parent;
    vector<int> ans;
    parent[A->val] = 0;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()) {
        A = q.front();
        if(A->val == B) break;
        q.pop();
        if(A->left != NULL) {
            q.push(A->left);
            parent[A->left->val] = A->val;
        }
        if(A->right != NULL) {
            q.push(A->right);
            parent[A->right->val] = A->val;
        }
    }
    int v = B;
    while(parent.find(v) != parent.end()) {
        ans.push_back(v);
        v = parent[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}