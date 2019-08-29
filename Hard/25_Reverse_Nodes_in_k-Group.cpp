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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL) return NULL;
        ListNode* temp = head;
        int len = 1;
        ListNode* NodeA = temp;

        while(temp != NULL && len <= m){

            len++;
            NodeA = temp;
            temp = temp->next;
        }

        //cout << "NodeA->val: " << NodeA->val << endl;
        //cout << "len: " << len << endl;

        ListNode* prev = NULL;
        ListNode* NodeB;
        ListNode* NodeB_END;
        ListNode* NodeC;
        temp = NodeA;
        len--;
        while(temp != NULL && len <= n){
            if(len <= n) {
                        NodeB = temp;
                        NodeC = NodeB->next;
                        //cout <<"NodeB->val: "<< NodeB->val << endl;
                        //if(NodeC != NULL) cout <<"NodeC->val: "<< NodeC->val << endl;
                    }
            //cout << "temp->val : " << temp->val << "  ";
            ListNode* temp2 = temp->next;
            temp->next = prev;
            if(prev == NULL) NodeB_END = temp;
            //cout << "temp->val: " << temp->val << " ";
            //cout << "temp->next->val: ";
            //if(temp->next == NULL) cout << "NULL" << endl;
            //else cout << temp->next->val << endl;
            prev = temp;
            temp = temp2;
            len++;
        }
        //cout <<"NodeB_END->val: "<< NodeB_END->val << endl;
        temp = new ListNode(0);
        temp->next = head;
        len = 1;
        while(temp != NULL && len < m){
            len++;
            //cout<<"*** temp->val: " << temp->val << endl;
            temp = temp->next;
            if(len == m) break;
        }
        if(m == 1) head = NodeB; //Ad-hoc check because it was not working for 1 to some other ranges
        else temp->next = NodeB;

        NodeB_END->next = NodeC;

        return head;
    }
    
    int getLen(ListNode* head){
        if(head == NULL) return 0;
        int len = 0;
        while(head != NULL){
            len++;
            head = head->next;
        }
        return len;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)  return NULL;
        
        int len = getLen(head);
        int m = 0;
        int i = 1;
        while(m + k <= len){
            head = reverseBetween(head, m + 1, k * i);
            m = m + k;
            i += 1;
        }
        return head;
        
    }
};