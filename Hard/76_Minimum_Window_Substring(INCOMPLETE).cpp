class Solution {
public:
    
    bool match_found(int arr1[], int arr2[]){
        for(int i = 0; i < 270; i++)
            if(arr1[i]  != arr2[i]) return false;
        return true;
    }
    
    string minWindow(string s, string t) {
        
        int ans = 10000000;
        int p_arr[270], s_arr[270];
        int begin_ind = 0;
        
        int start_ind = 0;
        int end_ind = 0;
        
        for(int i = 0; i < 270; i++){
            p_arr[i] = 0;
            s_arr[i] = 0;
        }
        
        for(int i = 0; i < t.size(); i++){
            p_arr[t[i] - '\0'] += 1;
        }
        
        while(p_arr[s[begin_ind++] - '\0'] == 0){}
        int garbage_char = 0;
        
        for(int i = begin_ind; i < s.size(); i++){
            
            if(p_arr[s[i] - '\0'] > 0){
                s_arr[s[i] - '\0'] += 1;
                if( match_found(p_arr, s_arr) == true){
                    ans = min(ans, i - begin_ind + 1);
                    if(ans > i - begin_ind + 1){
                        ans = i - begin_ind + 1;
                        start_ind = begin_ind;
                        end_ind = i;
                    }
                    if(garbage_char == 0) break;
                    else{
                        while(garbage_char > 0){
                            if(p_arr[s[begin_ind] - '\0'] == 0) garbage_char--;
                            begin_ind++;
                        }
                    }
                }
            }
            else garbage_char++;
        }
        string ans_str = "";
        for(int i = start_ind; i <= end_ind; i++)
            ans_str += s[i];
        
        return ans_str;
    }
};