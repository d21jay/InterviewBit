struct Node {
    int count = 0;
    unordered_map<char, Node*> links;
};
vector<string> Solution::prefix(vector<string> &A) {
    Node* B = new Node();
    Node* x;
    Node* y;
    char c;
    string s, s1;
    for(int i = 0; i < A.size(); i++) {
        s = A[i];
        x = B;
        for(int j = 0; j < s.size(); j++) {
            c = s[j];
            if(x->links.find(c) == x -> links.end()) {
                y = new Node();
                x->links[c] = y;
            }
            x->links[c]->count++;
            x = x->links[c];
        }
    }
    vector<string> ans;
    for(int i = 0; i < A.size(); i++) {
        s = A[i];
        x = B;
        s1 = "";
        for(int j = 0; j < s.size(); j++) {
            c = s[j];
            s1.push_back(c);
            if(x->links[c]->count == 1) break;
            else x = x->links[c];
        }
        ans.push_back(s1);
    }
    return ans;
}