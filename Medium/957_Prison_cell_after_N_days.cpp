class Solution {
public:
    
    int nextDay(int state){
        int ans = 0;

        // We only loop from 1 to 6 because 0 and 7 are impossible,
        // as those cells only have one neighbor.
        for (int i = 1; i <= 6; ++i) {
            if (((state >> (i-1)) & 1) == ((state >> (i+1)) & 1)) {
                ans ^= 1 << i;
            }
        }

        return ans;
        
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        map<int, int> seen;
        
        // state  = integer representing state of prison
        int state = 0;
        
        for(int i = 0; i < 8; i++){
            if(cells[i] > 0)
                state ^= 1 << i;
        }
        
        // While days remaining, simulate a day
        while (N > 0) {
            // If this is a cycle, fast forward by
            // seen.get(state) - N, the period of the cycle.
            if (seen.find(state) != seen.end()) {
                N %= seen[state] - N;
            }
            seen[state] = N;

            if (N >= 1) {
                N--;
                state = nextDay(state);
            }
        }
        
        // Convert the state back to the required answer.
        vector<int> ans(8, 0);
        for (int i = 0; i < 8; ++i) {
            if (((state >> i) & 1) > 0) {
                ans[i] = 1;
            }
        }

        return ans;
    }
};