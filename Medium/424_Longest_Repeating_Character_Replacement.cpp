//Work In Progress

/*
My testcases:

"ABAB"
2
"AAAABAACDAAFFFFFFFFFFFFFFFFFFF"
3

Output
4
30

Expected
4
22

*/

class Solution {
public:
    int find_min_index_char_val(int index[]){
        int ans = INT_MAX;
        int char_val;
        for(int i = 0; i < 26; i++){
            if(index[i] >= 0 && index[i] < ans) {
                ans = index[i];
                char_val = i;
            }
        }
        return char_val;
    }
    int characterReplacement(string s, int k) {
        int index[26];
        int arr[26];
        
        for(int i = 0; i < 26; i++){
            arr[i] = 0;
            index[i] = -1;
        }
        
        char max_char = '.';
        int max_freq = -1;
        int ans = -1;
        int i = 0;
        int total_so_far = 0;
        
        for(int j = 0; j < s.size(); j++){
            int char_val = s[i] - 'A';
            if(max_freq < arr[char_val] + 1){ //new max_char found or max_val will update!
                max_char = s[i];
                max_freq = arr[char_val] + 1;
                arr[char_val] = arr[char_val] + 1;
                
                if(index[char_val] == -1)
                    index[char_val] = j; //saving only first occurance for max
                total_so_far++;
            }
            else{
                if(total_so_far - max_freq + 1 <= k){ //add new element won't violate rule
                    arr[char_val] = arr[char_val] + 1;
                    index[char_val] = j;
                    total_so_far++;
                }
                else{ //violation will occur!
                    //we need to find min index
                    int min_index_char_val = find_min_index_char_val(index);
                    char min_index_char = 'A' + min_index_char_val;
                    index[min_index_char_val] = -1;
                    arr[min_index_char_val] = 0;
                    total_so_far--;
                    
                    arr[char_val] = arr[char_val] + 1;
                    index[char_val] = j;
                    total_so_far++;
                }
            }
            ans = max(ans, total_so_far);
        }//end-for
    return ans;
    }
};