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
    ListNode *H = A;
    while(A!=NULL && A->next !=NULL){
        if(A->next->val==A->val) A->next = A->next->next;
        A = A->next;
    }
    return A;
}