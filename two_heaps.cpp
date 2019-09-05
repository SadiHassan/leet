#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    multiset<double> lower; //max_heap
    multiset<double, greater<double> > higher; //min_heap

    void print(){
        cout << "lower (max_heap): " << endl;
        multiset <double, greater <double> > :: iterator itr_lower;
        for(itr_lower = lower.begin(); itr_lower != lower.end(); ++itr_lower)
            cout << *itr_lower << " ";
        cout << endl;
        cout << "higher (min_heap): " << endl;
        multiset <double, greater <double> > :: iterator itr_higher;
        for(itr_higher = higher.begin(); itr_higher != higher.end(); ++itr_higher)
            cout << *itr_higher << " ";
        cout << endl;
    }

    void add(double num){
        cout << "hi - 0" << endl;
        lower.insert(num);
        cout << "hi - 1" << endl;
        multiset <double, greater <double> > :: iterator itr_lower = lower.begin();
        cout << "hi - 2" << endl;
        higher.insert(*itr_lower);
        cout << "hi - 3" << endl;
        lower.erase(lower.find(*itr_lower));
        cout << "hi - 4" << endl;
        if(lower.size() < higher.size()){
            multiset <double> :: iterator itr_higher = higher.begin();
            lower.insert(*itr_higher);
            higher.erase(higher.find(*itr_higher));
        }
    }

    double avg(){
        multiset <double, greater <double> > :: iterator itr_lower = lower.begin();
        multiset <double> :: iterator itr_higher = higher.begin();

        if(lower.size() == higher.size()) return (*itr_lower + *itr_higher) / 2;
        return *itr_lower;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        if(nums.size() == 0) return ans;
        int j = 0;
        //cout << nums.size() << endl;
        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << endl;
            add((double) nums[i]);
            if(i - j >= k - 1){
                //print();
                ans.push_back(avg());
                if(lower.find(nums[j])==lower.end())
                    higher.erase(higher.begin(), higher.find(nums[j]));
                else
                    lower.erase(lower.begin(), lower.find(nums[j]));
                j++;
            }
        }
        return ans;
    }
};

int main(){

    int k = 3;
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(-1);
    arr.push_back(-3);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(6);
    arr.push_back(7);

    Solution* p;
    vector<double> ans = p->medianSlidingWindow(arr, k);
    cout << "Output:" << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
return 0;
}
