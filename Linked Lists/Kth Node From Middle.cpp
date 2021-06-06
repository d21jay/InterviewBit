/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    //we can implement this method in one pass. but why to worry!
    int n = 0;
    ListNode* x = A;
    while(!x == NULL) {
        n++;
        x = x -> next;
    }
    n = n/2 + 1; //weird formula
    if(B >= n) return -1;
    n = n - B;
    x = A;
    while(n > 1) {
        n--;
        x = x->next;
    }
    return x->val;
}