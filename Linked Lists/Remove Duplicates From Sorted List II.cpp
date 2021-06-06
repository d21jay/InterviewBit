/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A == NULL) return A;
    ListNode* x = A;
    ListNode* tx = new ListNode(A->val - 1);
    ListNode* ta = tx;
    tx -> next = A;
    ListNode* y = A -> next;
    int val = A -> val;
    while(!y == NULL) {
        if(val != y->val) {
            x -> next = y;
            tx = x;
            x = y;
            val = x -> val;
        }
        else {
            x = tx;
            x -> next = NULL;
        }
        y = y->next;
    }
    return ta->next;
}