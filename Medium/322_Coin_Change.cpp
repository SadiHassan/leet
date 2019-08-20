/*
[2,5,10,1]
27
Output: 8
Expected: 4

[186,419,83,408]
6249
TLE
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int dp[10000];

class Solution {
public:

    int rec(vector<int>& coins, int amount){
        if(amount < 0) return -1;
        if(amount == 0) return 0;
        if(dp[amount] != 0) return dp[amount];
        int ans = INT_MAX;

        for(int i = 0; i < coins.size(); i++){
            if(amount - coins[i] >= 0){
                int res =  rec(coins, amount - coins[i]);
                if(res >= 0 && res < ans) ans = 1 + res;
            }
        }
        if(ans == INT_MAX) ans = -1;
        cout << "remaining: " << amount << " ans: " << ans << endl;
        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, 0, sizeof(dp));
        return rec(coins, amount);
    }
};

int main(){
    Solution* p;
    /*
    vector<int> v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(10);
    v.push_back(1);
    cout << p->coinChange(v, 27) << endl;
    */

    /*
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    cout << p->coinChange(v, 999) << endl;
    */

    vector<int> v;
    v.push_back(186);
    v.push_back(419);
    v.push_back(83);
    v.push_back(408);
    cout << p->coinChange(v, 6249) << endl;
    return 0;
}
