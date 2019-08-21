//ACCEPTED!!!!
#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > ans;

class Solution {
public:


    void rec(vector<int>& nums, int len, int ind, vector<int>& arr_so_far){
        if(len == 0){
            ans.push_back(arr_so_far);
            return;
        }
        if(ind >= nums.size()) return;
        for(int i = ind; i < nums.size(); i++){
            arr_so_far.push_back(nums[i]);
            rec(nums, len - 1, i + 1, arr_so_far);
            arr_so_far.pop_back();
        }
    }

    vector< vector<int> > subsets(vector<int>& nums) {
        vector<int> arr_so_far;
        int nums_len = nums.size();
        for(int len = 0; len <= nums.size(); len++)
            rec(nums, len, 0, arr_so_far);
        return ans;
    }
};

int main(){

Solution* p;
vector<int> input;
input.push_back(1);input.push_back(2);input.push_back(3);input.push_back(4);input.push_back(5);

vector< vector<int> > ans = p->subsets(input);

for(int i = 0; i < ans.size(); i++){
    if(ans[i].size()==0) cout << "[]";
    for(int j = 0; j < ans[i].size(); j++){
        cout << ans[i][j]<< " ";
    }
    cout << endl;
}

return 0;
}
