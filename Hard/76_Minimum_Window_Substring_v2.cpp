#include<iostream>
using namespace std;

class Solution {
public:

    bool match_found(int arr1[], int arr2[]){ //match_found(p_arr, s_arr)
        for(int i = 0; i < 500; i++)
            if(arr1[i]  > arr2[i]) return false;
        return true;
    }

    string minWindow(string s, string t) {

        int ans = 10000000;
        int p_arr[500], s_arr[500];

        int start_ind = -1;
        int end_ind = -1;

        for(int i = 0; i < 500; i++){
            p_arr[i] = 0;
            s_arr[i] = 0;
        }

        for(int i = 0; i < t.size(); i++){
            p_arr[t[i] - '\0'] += 1;
        }
        int left = 0, right = 0;

        while(right < s.size()){
                s_arr[s[right] - '\0'] += 1;

                if(match_found(p_arr, s_arr)){
                    if(ans > right - left + 1){
                        ans = right - left + 1;
                        start_ind = left;
                        end_ind = right;
                    }
                    s_arr[s[left] - '\0'] -= 1;
                    left++;
                    while(match_found(p_arr, s_arr) && left <= right){
                        if(ans > right - left + 1){
                            ans = right - left + 1;
                            start_ind = left;
                            end_ind = right;
                        }
                        s_arr[s[left] - '\0'] -= 1;
                        left++;
                    } //end inner while
                }
            right++;
        }



        string ans_str = "";
        if(start_ind < 0 ) return ans_str;
        for(int i = start_ind; i <= end_ind; i++)
            ans_str += s[i];

        return ans_str;
    }
};

int main(){
    Solution* p;
    cout << p->minWindow("bba", "ab") << endl;
    return 0;
}
