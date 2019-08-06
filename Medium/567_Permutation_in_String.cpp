class Solution {
public:
    
    bool match_found(int arr1[], int arr2[]){
        for(int i = 0; i < 27; i++)
            if(arr1[i]  != arr2[i]) return false;
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        
        int p_arr[27], s_arr[27];
        int begin_ind = 0;
        
        for(int i = 0; i < 27; i++){
            p_arr[i] = 0;
            s_arr[i] = 0;
        }
        
        for(int i = 0; i < s1.size(); i++){
            p_arr[s1[i] - 'a'] += 1;
        }
        
        for(int i = 0; i < s2.size(); i++){
            if(p_arr[s2[i] - 'a'] > 0){ //i.e. this character exists in p (pattern), so, check for anagram
                s_arr[s2[i] - 'a'] += 1;
                if(i - begin_ind + 1 == s1.size()){
                    if( match_found(p_arr, s_arr) == true){
                        //ans.push_back(begin_ind);
                        return true;
                    }
                        s_arr[s2[begin_ind] - 'a'] -= 1;
                        begin_ind += 1;
                }   
            }
            else{
                //clear s_arr[]
                for(int i = 0; i < 27; i++) s_arr[i] = 0;
                begin_ind = i + 1;
            }
        }//end-for
    
        return false;
    }
};