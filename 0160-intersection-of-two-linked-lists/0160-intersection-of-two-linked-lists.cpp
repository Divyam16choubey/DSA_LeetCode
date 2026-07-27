/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cur1 = headA;
        ListNode* cur2 = headB;
        int countA=0, countB = 0;
        while(cur1){
            countA++;
            cur1 = cur1->next;
        }
        while(cur2){
            countB++;
            cur2 = cur2->next;
        }
        cur1 = headA;
        cur2 = headB;
        while(countA > countB){
            countA--;
            cur1 = cur1->next;
        }
        while(countA < countB){
            countB--;
            cur2 = cur2->next;
        }
        while(cur1 != cur2){
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        if(!cur1){
            return NULL;
        }
        return cur1;

    }
};