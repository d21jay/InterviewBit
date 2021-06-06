/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> iot;
int itr;
BSTIterator::BSTIterator(TreeNode *root) {
    iot.clear();
    itr = 0;
    if( root == NULL) return;
    stack<pair<TreeNode*, bool>> s;
    s.push({root, false});
    TreeNode* x;
    bool p;
    while(!s.empty()){
        x = s.top().first;
        p = s.top().second;
        s.pop();
        if(p) iot.push_back(x -> val);
        else{
            if(x -> right != NULL) s.push({x -> right, false});
            s.push({x, true});
            if(x -> left != NULL) s.push({x -> left, false});
        }
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return (itr < iot.size());
}

/** @return the next smallest number */
int BSTIterator::next() {
    itr++;
    return(iot[itr - 1]);
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */