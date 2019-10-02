class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0) return s;
        vector<string> arr;
        string str = "";
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == ' ') {
                if(str.size() > 0){
                    string temp = "";
                    for(int j = str.size() - 1 ; j >= 0; j--) temp += str[j];
                    arr.push_back(temp);
                }
                str = "";
                continue;
            }
            str += s[i];
        }
        
        if(str.size() > 0){
            string temp = "";
            for(int j = str.size() - 1 ; j >= 0; j--) temp += str[j];
            arr.push_back(temp);
        } 
        
        //for(int i = 0; i < arr.size(); i++) cout << arr[i] << endl;
        
        int i = 0;
        string ans = "";
        int ind = 0;
        bool space_added = false;
        while( i < s.size()){
            if(s[i] == ' '){
                if(!space_added){
                    ans += s[i];
                    space_added = true;
                }
                    
                i++;
                continue;
            }            
            space_added = false;
            while(s[i] != ' ' && i < s.size()){
                i++;
            }
            if(ind < arr.size())
                ans += arr[ind++];
        }
        if(ans.size() == 0) return ans;
        int start = 0, end = ans.size() - 1;
        string ans2 = "";
        while(ans[start] == ' '){
            start++;
            if(start >= ans.size()) return "";
        }
        
        while(ans[end] == ' '){
            end--;
            if(end < 0) return "";
        }
        
        for(int i = start; i <= end; i++) ans2 += ans[i];
        return ans2;
    }
};