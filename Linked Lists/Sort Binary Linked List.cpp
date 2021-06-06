/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    //there is better way to do in O(n) with moving the actual node. but, ok.
    int z = 0;
    ListNode* x = A;
    while(!x == NULL) {
        if(x -> val == 0) z++;
        x = x -> next;
    }
    x = A;
    while(z > 0) {
        z--;
        x -> val = 0;
        x = x -> next;
    }
    while(!x == NULL) {
        x -> val = 1;
        x = x -> next;
    }
    return A;
}