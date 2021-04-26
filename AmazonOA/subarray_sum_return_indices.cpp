#include <bits/stdc++.h>

using namespace std;

vector<int> target_sum_indices(vector<int> arr, int target){
    map<int, int> m;
    m[0] = 0;
    int sum_so_far = 0;

    for(int i = 0; i < arr.size(); i++){

        sum_so_far += arr[i];
        int remaining = sum_so_far - target;

        if(m.find(remaining) != m.end())
        return {m[remaining], i + 1};

        m[sum_so_far] = i + 1;
    }
    return {};
}


int main(){

vector<int> input;

/*
int target = 5;
input.push_back(1);
input.push_back(3);
input.push_back(-3);
input.push_back(8);
input.push_back(5);
input.push_back(7);
*/

/*
int target = 3;
input.push_back(1);
input.push_back(1);
input.push_back(1);
*/

int target = 7;
input.push_back(1);
input.push_back(-20);
input.push_back(-3);
input.push_back(30);
input.push_back(5);
input.push_back(7);

vector<int> ans = target_sum_indices(input, target);
for(auto x: ans)
    cout << x << " ";
cout << endl;
return 0;
}

/*
1 3 -3 8 5 7
5
1 1 1
3
1 -20 -3 30 5 7
7

*/
