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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* first = new ListNode(0);
        first->next = head;
        head = first;
        int x;
        ListNode* second, *prev, *cur, *fut;
        while(first->next != NULL){
            ListNode* temp = first;
            for(int i=0; i<k; i++){
                temp = temp->next;
                if(temp == NULL){
                    ListNode* tail = head;
                    head = head->next;
                    delete tail;
                    return head;
                }
            }
            x = k;
            second = first->next;
            prev = first;
            cur = first->next;
            while(x && cur){
                fut = cur->next;
                cur->next = prev;
                prev = cur;
                cur = fut;
                x--;
            }
            first->next = prev;
            second->next = cur;
            first = second;
        }
        first = head;
        head = head->next;
        delete first;
        return head;
    }
};