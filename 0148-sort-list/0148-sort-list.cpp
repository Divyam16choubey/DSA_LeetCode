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
    ListNode* middleNode(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* temp = new ListNode(0);
        ListNode* tail = temp;
        while(list1 && list2){
            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
                tail = tail->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
                tail = tail->next;
            }
        }
        if(list1){
            tail->next = list1;
        }else{
            tail->next = list2;
        }
        return temp->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* middle = middleNode(head);

        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;

        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};