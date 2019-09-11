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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        do{
            slow = slow->next;
            if(slow == NULL || fast == NULL) return NULL;
            fast = fast->next;
            if(fast == NULL) return NULL;
            fast = fast->next;
        }while(slow != fast);
        
        fast = head;
        while(fast!= slow){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};