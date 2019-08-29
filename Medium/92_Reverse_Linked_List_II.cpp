//Work in progress
#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /*
    ListNode* reverseList(ListNode* head, int n, ListNode* lastNode){
        if(head == NULL) return NULL;
        ListNode* prev = lastNode;
        int len = 1;
        while(head != NULL && len < n){
            len++;
            cout << "head: " << head->val << endl;
            ListNode* temp = head->next;
            head->next = prev;
            cout << "head->next: " << head->next->val << endl;
            prev = head;
            //if(len == n) break;
            head = temp;

        }
        cout << "returned head: "<< head->val << endl;
        return head;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL) return NULL;
        ListNode* temp = head;
        int m_keep = m;
        while(temp != NULL && m > 1){
            m = m -1;
            temp = temp->next;
        }
        ListNode* firstNode = temp;

        int len = 0;
        ListNode* lastNode = firstNode;

        while(len < n - m && lastNode != NULL){
            len += 1;
            lastNode = lastNode->next;
        }
        cout << "temp->val: "<< temp->val << endl;
        cout << "firstNode->val: "<< firstNode->val << endl;
        cout << "lastNode->val: "<< lastNode->val << endl;
        temp = reverseList(firstNode, n - m + 1, lastNode);


        len = 1;
        ListNode* temp2 = head;
        while(len < m && temp2 != NULL){
            len++;
            temp2 = temp2->next;
        }
        cout << "temp2->val: "<< temp2->val << endl;
        temp2->next = temp;

        return head;
    }
    */

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
};

int main(){

Solution* p;

int m = 1;
int n = 2;

ListNode* temp = new ListNode(1);
ListNode* input = temp;

temp->next = new ListNode(2);
temp = temp->next;
/*
temp->next = new ListNode(3);
temp = temp->next;

temp->next = new ListNode(4);
temp = temp->next;

temp->next = new ListNode(5);
temp = temp->next;

temp->next = new ListNode(6);
temp = temp->next;
*/
temp->next = NULL;

ListNode* head = p->reverseBetween(input, m, n);
while(head != NULL){
    cout << head->val << " ";
    head = head->next;
}
return 0;
}
