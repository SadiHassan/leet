#include <iostream>
#include <stack>

using namespace std;

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
