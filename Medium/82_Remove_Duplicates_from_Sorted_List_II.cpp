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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* p = new ListNode(0);
        p->next = head;
        
        head = p;
        
        while(head->next != NULL){
            bool found = false;
            while(head->next != NULL && head->next->next != NULL && head->next->val == head->next->next->val){
                found = true;
                head->next = head->next->next;
                if(head->next != NULL && head->next->next != NULL && head->next->val != head->next->next->val){
                    head->next = head->next->next;
                    break;
                }
                if(head->next->next == NULL) {head->next = head->next->next; break;}
            }
            
            if(!found)
                head = head->next;                
            if(head == NULL) break;   
        }
        
        return p->next;
    }
};