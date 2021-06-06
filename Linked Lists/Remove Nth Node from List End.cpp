/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int n = 0;
    if(A == NULL) return A;
    ListNode* x = A;
    while(!x == NULL) {
        n++;
        x = x -> next;
    }
    if(B >= n) return A -> next;
    n -= B;
    x = A;
    while(n > 1) {
        x = x -> next;
        n--;
    }
    x -> next = x -> next -> next;
    return A;
}