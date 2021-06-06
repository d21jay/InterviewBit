/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A == NULL) return A;
    stack<TreeNode*> s;
    TreeNode* y;
    TreeNode* x = A;
    if(x -> right != NULL) s.push(x -> right);
    if(x -> left != NULL) s.push(x -> left);
    x -> left = NULL;
    x -> right = NULL;
    y = A;
    while(!s.empty()){
        x = s.top();
        s.pop();
        y -> right = x;
        y = x;
        if(x -> right != NULL) s.push(x -> right);
        if(x -> left != NULL) s.push(x -> left);
        x -> left = NULL;
        x -> right = NULL;
    }
    return A;
}