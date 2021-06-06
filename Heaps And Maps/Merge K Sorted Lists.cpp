/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool cc(ListNode* &a, ListNode* &b){
    return a->val <= b->val;
}
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    //NLogN. using priority queue will make NLogK.
    vector<ListNode*> nodes;
    ListNode* t;
    for(int i = 0; i < A.size(); i++) {
        t = A[i];
        while(t != NULL) {
            nodes.push_back(t);
            t = t->next;
        }
    }
    sort(nodes.begin(), nodes.end(), cc);
    for(int i = 0; i < nodes.size(); i++) {
        nodes[i]->next = nodes[i+1];
    }
    nodes[nodes.size() - 1]->next = NULL;
    return nodes[0];
}