#include <bits/stdc++.h>
using namespace std;

/*
void strtok_single_delimeter(string str, char delimeter){

    stringstream check1(str);
    string intermediate;
    int tot = 0;
    while(getline(check1, intermediate, ' '))
    {
        //if(intermediate != " "){
            cout << intermediate << endl;
            tot++;
            cout << tot << endl;
        //}

    }
}

void strtok_multiple_delimeters(string inputString, string delimetr){

    std::stringstream stringStream(inputString);
    std::string line;

    while(std::getline(stringStream, line))
    {
        std::size_t prev = 0;
        std::size_t pos;
        while ((pos = line.find_first_of(delimetr, prev)) != std::string::npos)
        {
            if (pos > prev){
                string str = line.substr(prev, pos - prev);
                cout << str << endl;
            }
            prev = pos+1;
        }
        if (prev < std::string::npos){
            string str = line.substr(prev, std::string::npos);
            cout << str << endl;
        }

    }

}

int main(){
    //strtok_single_delimeter("abc efg hijk,   lmnop    qqq", ' ');
    strtok_multiple_delimeters("abc efg hijk, lmnop qqq", ",    ");
return 0;
}
*/


 struct ListNode {
   int val;
   ListNode *next;
   //ListNode(int x) : val(x), next(NULL) {}
   ListNode(int x){
    this->val = x;
    this->next = NULL;
   }
};


int main(){
    ListNode ob(55);
    cout << ob.val << endl;

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    ListNode* head = new ListNode(arr[0]);
    head->next = NULL;
    ListNode* cur = head;

    for(int i = 1; i < arr.size(); i++){
        ListNode* temp = new ListNode(arr[i]);
        temp->next = NULL;
        cur->next = temp;
        cur = cur->next;
    }

    cur = head;
    while(cur != NULL){
        cout << cur->val << endl;
        cur = cur->next;
    }

    return 0;
}


