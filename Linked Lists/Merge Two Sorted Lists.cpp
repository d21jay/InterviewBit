 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(A == NULL) return B;
    if(B == NULL) return A;
    ListNode* x = A;
    ListNode* y = B;
    ListNode* t;
    ListNode* tx = NULL;
    ListNode* ty = NULL;
    while(x != NULL && y != NULL) {
        if(x->val < y->val) {
            t = x->next;
            tx = NULL;
            x->next = y;
            if(ty != NULL)
                ty->next = x;
            ty = x;
            x = t;
        }
        else {
            t = y->next;
            ty = NULL;
            y->next = x;
            if(tx != NULL)
                tx-> next = y;
            tx = y;
            y = t;
        }
    }
    if(A->val < B->val) return A;
    else return B;
}