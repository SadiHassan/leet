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
        if(l1 == NULL && l2 == NULL) return NULL;
        if(l1 == NULL && l2 != NULL) return l2;
        if(l1 != NULL && l2 == NULL) return l1;
        
        ListNode* cur = new ListNode(0);
        ListNode* root;
        
        root = cur; //this means, root holds the address of cur
        
        while(l1 != NULL || l2 != NULL){ //if any of the list is alive, loop continues
            if(l1 == NULL){
                cur->next = l2; //cur->next will hold the address of l2
                l2 = l2->next; // l2 will move forward
                cur = cur->next; // Now basically cur = old l2
                continue;
            }
            
            if(l2 == NULL){
                cur->next = l1; //cur->next will hold the address of l1
                l1 = l1->next; // l1 will move forward
                cur = cur->next; // Now basically cur = old l1
                continue;
            }
            
            if(l1->val <= l2->val){
                cur->next = l1; //cur->next will hold the address of l1
                l1 = l1->next; // l1 will move forward
                cur = cur->next; // Now basically cur = old l1
            }
            else{
                cur->next = l2; //cur->next will hold the address of l2
                l2 = l2->next; // l2 will move forward
                cur = cur->next; // Now basically cur = old l2
            }    
        }
        
        /*
        Remember, root still has the address of cur. So, root->next has the address of  first node of the linked list. Because, when cur starts moving, it pointed to the first node using cur->next (that means, cur->next had the first node address). Since root still has the old most address of cur, root->next has address of the first node. OKA?
        */
        return root->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0) return NULL;
        
        int left = 0;
        int right = lists.size() - 1;
        
        
        while(1){
            //cout << lists.size() << endl;
            vector<ListNode*> lists_temp;
            while(left < right){
                ListNode* temp = mergeTwoLists(lists[left], lists[right]);
                lists_temp.push_back(temp);
                left++;
                right--;
            }
            
            if(left == right)
                lists_temp.push_back(lists[left]);
                
            
                if(lists_temp.size() == 1) return lists_temp[0];
                lists = lists_temp;
                left = 0;
                right = lists.size() - 1;
            }        
        
        return NULL;
    }
};