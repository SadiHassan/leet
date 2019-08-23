class Solution {
public:

    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        // write your code here
        int arr[128];
        for(int i = 0; i < 128; i++) arr[i] = -1;
        int i = 0;
        int distinct = 0;
        int ans = 0;
        
        for(int j = 0; j < s.size(); j++){
            
            if(arr[s[j] - NULL] == -1){ // New unique character
                arr[s[j] - NULL] = j;
                distinct++;
            }
            else arr[s[j] - NULL] = j; //Existing character, so just update the index
            
            if(distinct > k){
                distinct--;
                int min_ind = 1000000;
                int ind_of_arr = 0;
                for(int ii = 0; ii < 128; ii++){
                    if(arr[ii] >= 0 && arr[ii] < min_ind){
                        min_ind = arr[ii];
                        ind_of_arr = ii;
                    } 
                }
                arr[ind_of_arr] = -1; //remove the character which has maximum index
                i = min_ind + 1; //move i forward to the minimum index+1
            }//End IF
        
            if(distinct > 0 && distinct <= k) 
                ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
};