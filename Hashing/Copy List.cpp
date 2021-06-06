/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if(A == NULL) return NULL;
    vector<RandomListNode*> An;
    unordered_map<int, int> loc;
    RandomListNode* point = A;
    int s = 0;
    while(point != NULL){
        An.push_back(new RandomListNode(point -> label));
        loc.insert({point -> label, s});
        s++;
        point = point -> next;
    }
    point = A;
    s = 0;
    while(point != NULL){
        if(point -> next != NULL){
            An[s]->next = An[s + 1];
        }
        else An[s]->next = NULL;
        if(point -> random != NULL){
            An[s]->random = An[loc[point -> random -> label]];
        }
        else An[s]->random = NULL; 
        s++;
        point = point -> next;   
    }
    return An[0];
}