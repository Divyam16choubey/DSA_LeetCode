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
       
        unordered_map<Node*, Node*> m;
        while(temp){
            m[temp] = tail;
            temp = temp->next;
            tail = tail->next;
        }
        temp = head;
        tail = newHead;

        while(temp){
            tail->random = m[temp->random];
            tail = tail->next;
            temp = temp->next;
        }
        return newHead;

    }
};