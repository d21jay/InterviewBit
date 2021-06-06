bool cc(pair<int, int> &a, pair<int,int> &b) {
    return a.first > b.first;
}
struct Node{
    int val;
    Node* left;
    Node* right;
    int le;
    int re;
    Node(int x) : val(x), left(NULL), right(NULL), le(0), re(0) {}
};
vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    vector<pair<int, int>> hif;
    for(int i = 0; i < A.size(); i++) {
        hif.push_back({A[i], B[i]});
    }
    sort(hif.begin(), hif.end(), cc);
    Node* x =  new Node(hif[0].first);
    Node* y;
    Node* t;
    int n, v;
    for(int i = 1; i < hif.size(); i++) {
        v = hif[i].first;
        n = hif[i].second + 1;
        t = new Node(v);
        y = x;
        while(true) {
            if(n > y->le + 1) {
                y->re++;
                if(y->right == NULL) {
                    y->right = t;
                    break;
                }
                n = n - (y-> le + 1);
                y = y->right;
            }
            else {
                y->le++;
                if(y->left == NULL) {
                    y->left = t;
                    break;
                }
                y = y->left;
            }
        }
    }
    stack<pair<Node*, bool>> s;
    s.push({x, false});
    bool p;
    vector<int> ans;
    while(!s.empty()){
        y = s.top().first;
        p = s.top().second;
        s.pop();
        if(p) ans.push_back(y -> val);
        else{
            if(y -> right != NULL) s.push({y -> right, false});
            s.push({y, true});
            if(y -> left != NULL) s.push({y -> left, false});
        }
    }
    return ans;
}