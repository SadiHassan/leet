class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int dup = 0;
        bool found = false;
        int DUMB = -99999;
        
        int i = 0;
        while(i < nums.size()){
            bool found = false;
            if(i + 1 < nums.size()){
                if(nums[i] == nums[i + 1]){
                    if( i + 1 + 1 < nums.size()){
                        int j = i;
                        i = i + 2;
                        found = true;
                        while(i < nums.size() && nums[i] == nums[j]){
                            
                            nums[i] = DUMB;
                            i++;
                            if(i >= nums.size()) break;
                        }
                    }
                }
            }
            if(!found)
            i++;
        }
        
        //cout<<"before: "; for(int i = 0; i < nums.size(); i++) cout << nums[i] << " "; cout << endl;
        i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != DUMB){
                nums[i] = nums[j];
                i++;
            }
            else{
                int temp = nums[j];
                
            }
        }
        return i;
        /*
        cout<<"after: "; for(int i = 0; i < nums.size(); i++) cout << nums[i] << " "; cout << endl;
        int len = 0;
        for(int i = 0; i < nums.size(); i++) if(nums[i] == DUMB) break; else len++;
        return len;
        */
    }
};