class Solution {
public:
    int c_arr[30];
    int w_arr[30];
    
    void init(){
        for(int i = 0; i < 30; i++)
            w_arr[i] = 0;
    }
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        for(int i = 0; i < 30; i++)
            c_arr[i] = 0;
        
        for(int i = 0; i < chars.size(); i++)
            c_arr[chars[i] - 'a'] += 1;
        
        for(int j = 0; j < words.size(); j++){
            string str = words[j];
            init();
            
            for(int i = 0; i < str.size(); i++)
                w_arr[str[i] - 'a'] += 1;
            
            bool found = true;
            
            for(int i = 0; i < 30; i++){
                if(w_arr[i] > c_arr[i]){
                    found = false;
                    break;
                }
            }
            if(found)
                ans += str.size();
        }
        
        return ans;
    }
};