/*
"abcabcbb"
"bbbbb"
"pwwkew"
"dvdf"
"abba"
"tmmzuxt"
"abc"

out
4
2
4
4
4
7
-
exp
3
1
3
3
2
5
3

*/
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        map<char, int> m;
        int i = 0;
        int ans = 0;
        /*
        for(int j = 0; j < s.size(); j++){
            ans = max(ans, j - i);
            if(m.find(s[j]) == m.end()){ //new element
                m[s[j]] = j; //save index of first occurance

            }
            else{
                i = m[s[j]];
                m[s[j]] = j;
            }
        }
        */
        for(int j = 0; j < s.size(); j++){
            if(m.find(s[j]) != m.end()){ //element already exists in map
                i = max(i, m[s[j]]); //Why not i = m[s[j]] ?????????????????????????????????????
                /*
                If /i/ is already ahead of m[s[j]] and we update /i/ as "i = m[s[j]]", then /i/ will fall behind.
                */
            }
            ans = max(ans, j - i + 1);
            m[s[j]] = j + 1; //Why not m[s[j]] = j ?????????????????????????????????????????????
        }
        return ans;
    }
};

int main(){
	Solution* p;                                             //Exp Output
	cout << "abcabcbb" << " : "<< p->lengthOfLongestSubstring("abcabcbb") << " Exp: 3" <<endl; // 3
	cout << "bbbbb" << " : "<< p->lengthOfLongestSubstring("bbbbb") << " Exp: 1" <<endl; // 1
	cout << "pwwkew" << " : "<< p->lengthOfLongestSubstring("pwwkew") << " Exp: 3" <<endl; // 3
	cout << "dvdf" << " : "<< p->lengthOfLongestSubstring("dvdf") << " Exp: 3" <<endl; // 3
	cout << "abba" << " : "<< p->lengthOfLongestSubstring("abba") << " Exp: 2" <<endl; // 2
    cout << "tmmzuxt" << " : "<< p->lengthOfLongestSubstring("tmmzuxt") << " Exp: 5" <<endl; // 5
    cout << "abc" << " : "<< p->lengthOfLongestSubstring("abc") << " Exp: 3" <<endl; // 3

	return 0;
}
