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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* slow;
        ListNode* fast;
        slow = fast = head;
        while(1){
            if(fast == NULL || fast->next == NULL) return slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};