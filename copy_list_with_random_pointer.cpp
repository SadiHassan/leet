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
        unordered_map<Node*,Node*>map;
        Node* curr=head;
        Node* pre=new Node(0);
        Node* prehead=pre;
        while(curr!=NULL){
            Node* temp=new Node(curr->val);
            pre->next=temp;
            pre=pre->next;
            map[curr]=pre;
            curr=curr->next;
        }
        pre=prehead->next;
        curr=head;
        while(curr!=NULL){
            pre->random = map[curr->random];
            pre=pre->next;
            curr=curr->next;
        }
        return prehead->next;
    }
};