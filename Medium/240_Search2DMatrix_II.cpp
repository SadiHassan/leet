//O(n + nlog(m)) solution (My code)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> ind;
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i].size()==0) continue;
            if(target>=matrix[i][0] && target<=matrix[i][matrix[i].size()-1]) ind.push_back(i);
        }       
        
        for(int j=0; j<ind.size(); j++){
            int i = ind[j];
            int low=0, high=matrix[i].size()-1, med;
            while(low<=high){
                med = low + (high-low)/2;
                if(target < matrix[i][med]) high = med-1;
                else if(target > matrix[i][med]) low = med+1;
                else return true;
            }
        }
        return false;
    }
};

//O(max(n, m)) solution (other solution, better... as always! Sigh!! )

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0, c = matrix.size() > 0 ? matrix[0].size() - 1 : 0;
        
        while(r < matrix.size() && c >= 0)
            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] < target) ++r;
            else --c;
        
        return false;
    }
};