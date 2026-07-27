/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* cur = head;
        int count = 0;
        while(cur){
            count++;
            cur = cur->next;
        }
        k = k%count;
        if(k==0){
            return head;
        }
        count -= k;
        ListNode* prev = NULL;
        cur = head;
        while(count--){
            prev = cur;
            cur = cur->next;
        }
        prev->next = NULL;
        ListNode* tail = cur;
        while(tail->next){
            tail = tail->next;
        }
        tail->next = head;
        return cur;
    }
};