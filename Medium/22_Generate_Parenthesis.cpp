class Solution {
public:
    vector<string> ans;
    
    void rec(string str, int open, int close, int n){
        
        if(str.size() == 2 * n) {
            ans.push_back(str);
            return;
        }
        
        if(open < n) rec(str + '(', open + 1, close, n);
        if(close < open) rec(str + ')', open, close + 1, n);
    }
    
    vector<string> generateParenthesis(int n) {
        if(n == 0) return ans;
        string str = "";
        rec(str, 0, 0, n);
        return ans;
    }
};