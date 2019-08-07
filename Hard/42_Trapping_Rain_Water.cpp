#include <iostream>
#include <vector>
using namespace std;
/*

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Trapping Rain Water!!!!!!!!!!!!!
Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Trapping Rain Water!!!!!!!!

Next challenges:
Trapping Rain Water II
Pour Water

Input:
[0,1,0,2,1,0,1,3,2,1,2,1]
[2,0,2]
[6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3]

Output:
6
2
86

Expected:
6
2
83
*/


class Solution {
public:
    int trap(vector<int>& height) {

        if(height.size() <= 1) return 0;

        vector<int> taken(height.size(), 0);

        int left = 0;
        while(height[left] == 0) left++;
        int right = left + 1;

        int ans = 0;

        while(left < right && right < height.size()){

            if(height[right] >= height[left]){
                taken[right] = 1;
                taken[left] = 1;
                int width = right - left - 1;
                int h = min(height[left], height[right]);
                int area = width * h;
                int j = right - 1;
                while(j > left){
                    if(height[j] < height[left]) area -= height[j];
                    j--;
                }
                ans += area;
                //cout<<"left: "<<left<<" right: "<<right<<" ans: "<<ans<< " area: "<<area<<endl;
                left = right;
            }

            right++;
        }

        right = height.size()-1;
        while(height[right] == 0) right--;
        left = right - 1;

        while(left < right && left >= 0){
            if(height[left] >= height[right] && !(taken[left] == 1 && taken[right] == 1)){

                int width = right - left - 1;
                int h = min(height[left], height[right]);
                int area = width * h;
                int j = left + 1;

                while(j < right){
                    if(height[j] < height[right]) area -= height[j];
                    j++;

                }

                ans += area;
                //cout<<"[2]left: "<<left<<" right: "<<right<<" ans: "<<ans<< " area: "<<area<<endl;
                right = left;
            }

            left--;
        }

        return ans;
    }
};

int main(){
Solution* p = new Solution();
//vector <int> vect { 6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3 };

static const int arr[] = {6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3};
vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
cout << p->trap(vec) << endl;

static const int arr2[] = {2,0,2};
vector<int> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
cout << p->trap(vec2) << endl;

static const int arr3[] = {0,1,0,2,1,0,1,3,2,1,2,1};
vector<int> vec3 (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]) );
cout << p->trap(vec3) << endl;

}
