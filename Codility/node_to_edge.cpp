/*
http://mathworld.wolfram.com/VertexDegree.html

sum of all degrees = 2 * E
E = total number of edges
*/
#include <bits/stdc++.h>
using namespace std;

int main(){

vector<int> arr;
arr.push_back(1);
arr.push_back(3);
arr.push_back(4);
/*
arr.push_back(10);
arr.push_back(10);
arr.push_back(10);
arr.push_back(10);
arr.push_back(10);
arr.push_back(10);
arr.push_back(10);
*/

sort(arr.begin(), arr.end());

int i = 0;
int j = arr.size() - 1;
int total_edge = 0;

while(i < j){
    if(arr[i] <= arr[j]){
        total_edge += arr[i];
        arr[j] -= arr[i];
        arr[i] = 0;
        i++;
    }
    else if(arr[j] <= arr[i]){
        total_edge += arr[j];
        arr[i] -= arr[j];
        arr[j] = 0;
        j--;
    }

}
cout << total_edge << endl;
return 0;
}
