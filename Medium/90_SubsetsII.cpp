#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector< vector<int> > ans;
map< vector<int>, bool> m;
int freq[100];

class Solution {
public:

    void rec(vector<int>& nums, int len, int ind, vector<int>& arr_so_far){
        if(len == 0){
            //sort(arr_so_far.begin(), arr_so_far.end());
            if(m.find(arr_so_far) == m.end()){
                    m[arr_so_far] = true;
                    ans.push_back(arr_so_far);
            }

            return;
        }
        for(int i = ind; i < nums.size(); i++){
            if(freq[nums[i]] > 0){
                arr_so_far.push_back(nums[i]);
                freq[nums[i]] -= 1;
                rec(nums, len - 1, i + 1, arr_so_far);
                arr_so_far.pop_back();
                freq[nums[i]] += 1;
            }

        }
    }

    vector< vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<int> arr_so_far;
        sort(nums.begin(), nums.end());
        int nums_len = nums.size();
        for(int i = 0; i < 100; i++) freq[i] = 0;
        for(int i = 0; i < nums.size(); i++) freq[nums[i]] += 1;

        for(int len = 0; len <= nums.size(); len++){
            arr_so_far.clear();
            rec(nums, len, 0, arr_so_far);
        }

        //rec(nums, 2, 0, arr_so_far);
        return ans;
    }
};

int main(){

Solution* p;
vector<int> input;
input.push_back(4);input.push_back(4);input.push_back(4);input.push_back(1);input.push_back(4);

vector< vector<int> > ans = p->subsetsWithDup(input);

for(int i = 0; i < ans.size(); i++){
    if(ans[i].size()==0) cout << "[]";
    for(int j = 0; j < ans[i].size(); j++){
        cout << ans[i][j]<< " ";
    }
    cout << endl;
}

return 0;
}
