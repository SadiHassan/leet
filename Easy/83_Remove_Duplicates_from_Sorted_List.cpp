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
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        while(temp->next != NULL){
            while(temp->next != NULL && temp->val == temp->next->val){
                //cout << temp->val << " --> " << temp->next->val << endl;
                temp->next = temp->next->next;
            } 
                
            temp = temp->next;                
            if(temp == NULL) break;
        }
        return head;
    }
};