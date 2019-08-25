class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int pos = 0;
        int arr[30];
        for(int i = 0; i < 30; i++) arr[i] = 0;
        for(int i = 0; i < keyboard.size(); i++)
            arr[keyboard[i] - 'a'] = i;
        
        int ans = 0;
        for(int i = 0; i < word.size(); i++){
            ans += abs(pos - arr[word[i] - 'a']);
            pos = arr[word[i] - 'a'];
        }
        return ans;
    }
};