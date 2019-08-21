#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int len = A.size();
        int freq[len][27];

        for(int i = 0; i < len; i++)
            for(int j = 0; j < 27; j++)
                freq[i][j] = 0;

        for(int i = 0; i < len; i++){
            for(int j = 0; j < A[i].size(); j++){
                freq[i][A[i][j] - 'a'] += 1;
            }
        }
        /*
        for(int i = 0; i < len; i++){
            for(int j = 0; j < 27; j++)
                cout << freq[i][j] << " ";
            cout << endl;
        }
        */

        vector<string> ans;

        for(int j = 0; j < 27; j++){ //for each character

            int min_freq = 10000;

            for(int i = 0; i < len; i++){ //for each word
                if(freq[i][j] != 0){
                    min_freq = min(min_freq, freq[i][j]);
                }
                if(freq[i][j] == 0){
                    min_freq = 10000;
                    break;
                }
            }

            if(min_freq == 10000) continue;
            //cout << j << " --> " << min_freq << endl;
            for(int k = 1; k <= min_freq; k++){
                char ch = 'a' + j;
                string str = "";
                str += ch;
                ans.push_back(str);
            }
        }

        return ans;
    }
};

int main(){

    Solution* p;
    vector<string> input;

    input.push_back("bella"); input.push_back("label"); input.push_back("roller");
    vector<string> ans = p->commonChars(input);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
