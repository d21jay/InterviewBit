/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSymmetric(TreeNode* A) {
    if(A == NULL) return 1;
    stack<pair<TreeNode*, bool>> s1;
    stack<pair<TreeNode*, bool>> s2;
    s1.push({A, false});
    s2.push({A, false});
    TreeNode* x;
    TreeNode* y;
    TreeNode* z = new TreeNode(-1);
    //using -1 as it is reserves as leaf value in input, so won't be issue.
    bool p1, p2;
    while(!s1.empty()){
        x = s1.top().first;
        p1 = s1.top().second;
        y = s2.top().first;
        p2 = s2.top().second;
        if(x->val != y->val) return 0;
        s1.pop();
        s2.pop();
        if(!p1){
            if(x -> right != NULL) s1.push({x -> right, false});
            else s1.push({z,true});
            s1.push({x, true});
            if(x -> left != NULL) s1.push({x -> left, false});
            else s1.push({z,true});
        }
        if(!p2){
            if(y -> left != NULL) s2.push({y -> left, false});
            else s2.push({z, true});
            s2.push({y, true});
            if(y -> right != NULL) s2.push({y -> right, false});
            else s2.push({z,true});
        }
    }
    return 1;
}