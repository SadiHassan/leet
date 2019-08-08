#include <iostream>
#include <stack>

using namespace std;

//----------------- STRUCTURE DECLARATION -----------------//
struct num_type{
    int num;
    int index;
};

//----------------- SORT COMPARE FUNCTION -----------------//
static bool comp(num_type a, num_type b){
    return (a.num <= b.num);
}

//----------------- PASSING ARRAY TO A FUNCTION (WAY-1) -----------------//
//call --> match_found(arr1, arr2);
bool match_found(int arr1[], int arr2[]){
        for(int i = 0; i < 27; i++)
            if(arr1[i]  != arr2[i]) return false;
        return true;
    }

//----------------- Leet_1_TWO_SUM -----------------//

vector<int> twoSum(vector<int>& nums, int target) {
        vector<num_type> arr;
        for(int i=0; i<nums.size();i++){
           num_type ob;
           ob.num = nums[i];
           ob.index = i;
           arr.push_back(ob);
        }
        sort(arr.begin(), arr.end(), comp);
        
		//----------------- BINARY SEARCH (BASIC) -----------------//
        int L=0;
        int R=arr.size()-1;
        
		while(L<R){
            if(arr[L].num+arr[R].num<target)
                L++;
            else if(arr[L].num+arr[R].num>target)
                R--;
            else break;
        }
        
        vector<int> answer;
        answer.push_back(arr[L].index);
        answer.push_back(arr[R].index);
        return answer;
    }
// TWO_SUM ENDS
	
int main(){

//----------------- STACK -----------------//
stack<int> st;
st.push(1);
st.push(2);
st.push(3);

while(!st.empty()){
    cout << st.top() << endl; //Output: 3 2 1
    st.pop();
}

//----------------- VECTOR  -----------------//

// Create a vector of SIZE = N ; Initialized with = 0
vector<int> _vec(N, 0);

return 0;
}
