/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::kthsmallest(TreeNode* A, int B) {
    if(A == NULL) return 0;
    stack<pair<TreeNode*, bool>> s;
    s.push({A, false});
    TreeNode* x;
    bool p;
    int itr = 0;
    while(!s.empty()){
        x = s.top().first;
        p = s.top().second;
        s.pop();
        if(p) {
            itr++;
            if(itr == B) return x -> val;
        }
        else{
            if(x -> right != NULL) s.push({x -> right, false});
            s.push({x, true});
            if(x -> left != NULL) s.push({x -> left, false});
        }
    }
    return 0;
}