/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* toBST(const vector<int> &A, int l, int r) {
    if(A.size() == 0 || l == r) return NULL;
    int m = (l + r)/2;
    TreeNode* x = new TreeNode(A[m]);
    x -> left = toBST(A, l, m);
    x -> right = toBST(A, m + 1, r);
    return x;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return toBST(A, 0, A.size());
}