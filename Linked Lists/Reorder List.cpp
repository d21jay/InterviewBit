/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    if(A == NULL) return A;
    ListNode* x = A;
    int n = 0;
    while(x != NULL) {
        x = x -> next;
        n++;
    }
    if(n == 1) return A;
    int m = (n + 1)/2;
    int c = 1;
    ListNode* u;
    ListNode* v;
    ListNode* w;
    x = A;
    while(c < m) {
        x = x->next;
        c++;
    }
    u = x -> next;
    v = u -> next;
    u -> next = NULL;
    while(!v == NULL) {
        w = v -> next;
        v -> next = u;
        u = v;
        v = w;
    }
    x -> next = NULL;
    x = A;
    while(!u == NULL) {
        v = u -> next;
        w = x -> next;
        x ->next = u;
        u -> next = w;
        u = v;
        x = w;
    }
    return A; 
}