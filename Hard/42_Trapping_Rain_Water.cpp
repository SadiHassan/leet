class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        while(height[left] == 0) left++;
        int right = left + 1;
        
        int ans = 0;
        
        while(left < right && right < height.size()){
            cout<<"left: "<<left<<" right: "<<right<<endl;
            if(height[right] >= height[left]){
                int width = right - left - 1;
                int h = min(height[left], height[right]);
                int area = width * h;
                int j = right - 1;
                while(j > left){
                    if(height[j] < height[left]) area -= height[j];
                    j--;
                }
                ans += area;
                left = right;
            }
            
            right++;
        }
    
        return ans;
    }
};