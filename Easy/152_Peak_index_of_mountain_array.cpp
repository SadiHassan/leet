class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        /*
        Runtime: 12 ms, faster than 96.77% of C++ online submissions for Peak Index in a                      Mountain Array.
        Memory Usage: 9.4 MB, less than 96.46% of C++ online submissions for Peak Index in a                       Mountain Array.
        
        */
        int max_index = 0;
        int max_val = -1;
        
        for(int i = 0; i < A.size(); i++){
            if(max_val < A[i]){
                max_val = A[i];
                max_index = i;
            }
        }
        
        return max_index;
        
        
        /*
        BINARY SEARCH SOLUTION
        Runtime: 16 ms, faster than 70.03% of C++ online submissions for Peak Index in a                      Mountain Array.
        Memory Usage: 9.4 MB, less than 92.92% of C++ online submissions for Peak Index in a                       Mountain Array.
        */
        
        /*
        int low = 0;
        int high = A.size() - 1;
        while(low < high){
            int med = low + (high - low)/2;
            if(A[med] < A[med + 1])
                low = med+1;
            else
                high = med;
        }
        
        return low;        
        */
    }
};