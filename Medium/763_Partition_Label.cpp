/* Worst Solution
scroll down to see the best one
*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        if(S.size() == 0) return {};
        vector<int> begin_ind(30, -1);
        vector<int> end_ind(30, -1);
        
        for(int i = 0; i < S.size(); i++){
            char ch = S[i];
            int ascii_relative_index = ch - 'a';
            if(begin_ind[ascii_relative_index] == -1)
                begin_ind[ascii_relative_index] = i;
            end_ind[ascii_relative_index] = i;
        }
        
        map<char, bool> m;
        vector<int> ind_arr;
        
        //ind_arr.push_back(0);
        int new_character = 0;
        for(int i = 0; i < S.size(); i++){
            if(m.find(S[i]) == m.end()){
                new_character++;
                m[S[i]] = true;
            }
            if(i == end_ind[S[i] - 'a']) new_character--;
            if(new_character == 0)
                ind_arr.push_back(i);
        }
        vector<int> ans;
        ans.push_back(ind_arr[0] + 1);
        
        for(int i = 1; i < ind_arr.size(); i++) 
            //cout << ind_arr[i] << endl;
            ans.push_back(ind_arr[i] - ind_arr[i - 1]);
        
        return ans;
    }
};

//Best Solution
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        int arr[27];
        memset(arr,0,sizeof(arr));
        for(int i=0; i<S.size(); i++) arr[S[i]-'a'] = i; //store the maximum index
        int anchor = 0, j=0;
        for(int i=0; i<S.size(); i++){
            j = max(j,arr[S[i]-'a']);
            if(j==i){
                ans.push_back(j-anchor+1);
                anchor = i+1;
            }
        }
        return ans;
    }
};