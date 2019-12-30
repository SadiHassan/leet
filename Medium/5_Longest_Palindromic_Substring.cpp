class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len==0) return "";
        int dp[len][len];
        memset(dp,0,sizeof(dp));
        int ans = -1;
        int beg = -1, end = -1;
        for(int i=0; i<len; i++) {
            dp[i][i] = 1;
            ans = 1;
            beg = i;
            end = i;
        }
        
        for(int window=2; window<=len; window++){
            for(int i=0; i<len-window+1; i++){
                int j = i + window -1;
                if(j==i+1 && s[i]==s[j]) {
                    dp[i][j] = 2;
                    if(ans < dp[i][j]){ ans = dp[i][j]; beg = i; end = j;}
                }
                else if(s[i]==s[j] && j-i -1 == dp[i+1][j-1]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                    if(ans < dp[i][j]){ ans = dp[i][j]; beg = i; end = j;}
                }
            }
        }
        
        
        string str = "";
        for(int i=beg; i<=end; i++) str += s[i];
        //return dp[0][len-1];
        return str;
    }
};