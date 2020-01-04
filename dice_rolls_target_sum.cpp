class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        // dp(i, j): no. of ways to get 'j' from 'i' die
        vector<vector<int> > dp(d+1, vector<int>(target + 1, 0));
        const long long MOD = pow(10, 9) + 7;
        // sum of 0 is always possible
        dp[0][0] = 1;
        
        for(int sum = 1; sum <= target; sum++) {
            for(int dices = 1; dices <= d; dices++) {
                // Each dice can contribute one face value for the current sum, so
                // iterate and check for all the face values of the current dice
                for(int faces = 1; faces <= f; faces++) {
                    // check if it is possible to get the remaining sum value with remaining die
                    int req_val = (sum - faces) >= 0 ? dp[dices - 1][sum - faces] : 0;
                    dp[dices][sum] = (dp[dices][sum] + req_val) % MOD;
                }
            }
        }
        return dp[d][target];
    }
};