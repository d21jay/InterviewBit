/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(A == NULL) return NULL;
    ListNode* x;
    ListNode* y;
    ListNode* t = new ListNode(0);
    t -> next = A;
    ListNode* tx = t;
    x = A;
    while(!x == NULL) {
        if(x -> next == NULL) break;
        y = x -> next;
        tx -> next = y;
        x -> next = y -> next;
        y -> next = x;
        tx = x;
        x = x -> next;
    }
    return t -> next;
}