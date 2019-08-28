class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        
        int ans = 0;
        
        int i = 0;
        int tot_zero = 0;
        
        for(int j = 0; j < A.size(); j++){
            if(A[j] == 0) tot_zero++;
            int ii = i;
            while(tot_zero > K){
                if(A[ii] == 0) tot_zero--;
                ii++;
                i = ii;
            }
            
            int len = j - i + 1;
            ans = max(ans, len);
        }
        return ans;
    }
};