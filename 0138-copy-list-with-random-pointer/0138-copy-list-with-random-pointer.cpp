/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* find(Node* cur1, Node* cur2, Node* x){
        if(x==NULL)
            return NULL;
        while(cur1 != x){
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur2;
    }
    Node* copyRandomList(Node* head) {
        Node* newHead = new Node(0);
        Node* tail = newHead;
        Node* temp = head;
        while(temp){
            tail->next = new Node(temp->val);
            tail = tail->next;
            temp = temp->next;
        }
        tail = newHead;
        newHead = newHead->next;
        delete tail;
        tail = newHead;
        temp = head;
        while(temp){
            tail->random = find(head, newHead, temp->random);
            tail = tail->next;
            temp = temp->next;
        }

        return newHead;
    }
};