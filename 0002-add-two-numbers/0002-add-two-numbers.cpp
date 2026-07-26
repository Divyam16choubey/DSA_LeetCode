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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first, *second;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;

        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        int carry = 0;
        while(cur1 && cur2){
            int sum = cur1->val + cur2->val + carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            cur1 = cur1->next;
            cur2 = cur2->next;
            carry = sum/10;
        }
        while(cur1){
            int sum = cur1->val + carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            cur1 = cur1->next;
            carry = sum/10;
        }
        while(cur2){
            int sum = cur2->val + carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            cur2 = cur2->next;
            carry = sum/10;
        }
        while(carry){
            tail->next = new ListNode(carry%10);
            tail = tail->next;
            carry /= 10;
        }
        head = head->next;
        return head;
    }
};