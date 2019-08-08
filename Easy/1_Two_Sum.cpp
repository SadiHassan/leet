class Solution {
public:
    struct num_type{
        int num;
        int index;
    };
    static bool comp(num_type a, num_type b){
        return (a.num <= b.num);
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<num_type> arr;
        for(int i=0; i<nums.size();i++){
           num_type ob;
           ob.num = nums[i];
           ob.index = i;
           arr.push_back(ob);
        }
        sort(arr.begin(), arr.end(), comp);
        
        int L=0;
        int R=arr.size()-1;
        while(L<R){
            if(arr[L].num+arr[R].num<target)
                L++;
            else if(arr[L].num+arr[R].num>target)
                R--;
            else break;
        }
        
        vector<int> answer;
        answer.push_back(arr[L].index);
        answer.push_back(arr[R].index);
        return answer;
    }
};