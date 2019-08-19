#include<iostream>
#include<map>
using namespace std;
/*
"eqgkcwGFvjjmxutystqdfhuMblWbylgjxsxgnoh"
16
Output
38
Expected
27
*/
class Solution {
public:

    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        if(k == 0)
            return 0;

        map<char, int> m;

        int i = 0;
        int ans = 0;

        for(int j = 0; j < s.size(); j++){
            if(m.find(s[j]) == m.end()){ // new element found that will make no of distinct character (map size) > k
                if(m.size() == k){ //window filled-up

                    ans = max(ans, j - i);

                    int ii = 1000000;
                    std::map<char, int>::iterator it_min;
                    for (std::map<char, int>::iterator it = m.begin(); it != m.end(); ++it){
                        if(ii > it->second){
                            ii = it->second;
                            it_min = it;
                        }
                    }
                    m.erase(it_min);

                    i = ii + 1;


                }
                    m[s[j]] = j;
                    if(j == (s.size() - 1) && (m.size() <= k))
                        ans = max(ans, j - i + 1);
            }
            else if(j == (s.size() - 1) && (m.size() <= k)){
                ans = max(ans, j - i + 1);
            }

            else {
                    m[s[j]] = j;
                    if(j == (s.size() - 1) && (m.size() <= k)){
                        ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};

int main(){
Solution* p;
/*
string input = "eqgkcwGFvjjmxutystqdfhuMblWbylgjxsxgnoh";
cout <<"ans: "<< p->lengthOfLongestSubstringKDistinct(input, 16) << endl;
*/
string input = "e";
cout <<"ans: "<< p->lengthOfLongestSubstringKDistinct(input, 1) << endl;

return 0;
}
