/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    //break from middle; reverse link 2nd part; compare and join back for 
    //O(1) space. doing O(n) space here.
    stack<int> s;
    ListNode* x = A;
    while(!x == NULL) {
        s.push(x -> val);
        x = x -> next;
    }
    x = A;
    while(!s.empty()) {
        if(x -> val != s.top()) return 0;
        x = x -> next;
        s.pop();
    }
    return 1;
}