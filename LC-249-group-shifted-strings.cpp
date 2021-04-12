#include <bits/stdc++.h>
using namespace std;

class Solution {

public:

    string getHash(string word){
        string hash_str = "_";

        for(int i = 1; i < word.size(); i++){
            int diff = word[i] - word[i - 1];
            if(diff < 0) diff += 26;
            hash_str += 'a' + diff + '_';
        }
        return hash_str;
    }

    vector< vector<string> > groupStrings(vector<string>& strings) {
        vector< vector<string> > ans;
        map< string, vector<string> > m;
        for(int i = 0; i < strings.size(); i++){
            m[getHash(strings[i])].push_back(strings[i]);
        }

        for(auto elem: m){
            ans.push_back(elem.second);
        }

        return ans;
    }
};


int main(){

Solution* p;
vector<string> input;
input.push_back("abc"); input.push_back("bcd"); input.push_back("acef"); input.push_back("xyz"); input.push_back("az");
input.push_back("ba"); input.push_back("a"); input.push_back("z");

vector< vector<string> > ans = p->groupStrings(input);
for(auto group: ans){
    for(auto word: group)
        cout << word << " ";
    cout << endl;
}

return 0;
}
