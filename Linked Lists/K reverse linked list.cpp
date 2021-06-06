/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    //Length is divisible by k;
    if(B == 1) return A;
    ListNode* x = A;
    ListNode* y;
    ListNode* z;
    ListNode* w;
    ListNode* w1 = x;
    int count = 1;
    bool found = false;
    y = x -> next;
    x->next = NULL;
    while(y != NULL) {
        z = y -> next;
        if(count % B == 0) {
            if(!found) A = x;
            else w -> next = x;
            found = true;
            w = w1;
            w1 = y;
            y->next = NULL;
        }
        else y -> next = x;
        x = y;
        y = z;
        count++;
    }
    if(found)
    w -> next = x;
    else A = x;
    return A;
}