/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Iterative Solution
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        
        ListNode* prev = NULL;
        
        while(head != NULL){    
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};
*/

//Recursive Solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) //No element in the list 
            return head;
        if(head->next == NULL) //One element-list OR one element remaining in the list
            return head;
        
        ListNode* tt = NULL;
        tt = reverseList(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return tt;
    }
};