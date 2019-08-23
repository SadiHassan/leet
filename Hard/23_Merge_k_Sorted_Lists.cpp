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
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2==NULL)
            return NULL;
        ListNode* p = new ListNode(0);
        ListNode* head;
        head = p;
        while(l1 != NULL || l2 != NULL){
            if(l1 == NULL && l2 != NULL){
                p->val = l2->val;
                if(l2->next == NULL)
                    p->next = NULL;
                else{
                    ListNode* temp = new ListNode(0);
                    p->next = temp;
                    p = p->next;
                }
                l2 = l2->next;                
            }
            else if(l2 == NULL && l1 != NULL){
                p->val = l1->val;
                if(l1->next == NULL)
                    p->next = NULL;
                else{
                    ListNode* temp = new ListNode(0);
                    p->next = temp;
                    p = p->next;
                }
                l1 = l1->next;
            }
            else{
                int val = min(l1->val, l2->val);
                p->val = val;
                ListNode* temp = new ListNode(0);
                p->next = temp;
                p = p->next;
                if(l1->val <= l2->val) {
                    l1 = l1->next;
                }
                    else {
                        l2 = l2->next;
                    }
            }
        }
        
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        
        int max_ind = lists.size() - 1;
        while(max_ind > 0){
            int ind = -1;
            for(int i = 0; i <= max_ind; i = i + 2){
                ind += 1;
                if(i + 1 <= max_ind){
                    lists[ind] = mergeTwoLists(lists[i], lists[i + 1]);
                }
                else{
                    lists[ind] = lists[i];
                }
            }
            max_ind = ind;
        }
        
        return lists[0];
    }
};