/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
  // going to apply floyd's cycle detection algorithm.
  ListNode* x;
  ListNode* y;
  x = A;
  y = A;
  bool cycle = false;
  while(true) {
      x = x -> next;
      if(x == NULL) break;
      y = y -> next;
      if(y == NULL) break;
      y = y -> next;
      if(y == NULL) break;
      else if(y == x) {
          cycle = true;
          break;
      }
  }
  if(cycle == false) return NULL;
  x = A;
  while(x != y) {
      x = x -> next;
      y = y -> next;
  }
  return x;
}