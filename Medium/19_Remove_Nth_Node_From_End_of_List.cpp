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
    
    int getLen(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head->next;
        }
        return len;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        
        int len = getLen(head);
        n = len - n + 1;
        int cur_node_id = 0;
        ListNode* head_keep;
        head_keep = head;
        if(n == 1){
            head = head->next;
            return head;
        }
        while(head_keep != NULL){
            cur_node_id++;
            if(cur_node_id + 1 == n){
                head_keep->next = head_keep->next->next;
                break;
            }
            head_keep = head_keep->next;
        }
        return head;
    }
};