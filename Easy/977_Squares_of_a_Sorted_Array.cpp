//Using Priority Queue
/*
Runtime: 136 ms, faster than 10.02% of C++ online submissions for Squares of a Sorted Array.
Memory Usage: 16.1 MB, less than 8.11% of C++ online submissions for Squares of a Sorted Array.
*/
/*
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < A.size(); i++)
            pq.push(A[i] * A[i]);
        
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
*/

//Using Sort
/*
Runtime: 132 ms, faster than 11.95% of C++ online submissions for Squares of a Sorted Array.
Memory Usage: 14.4 MB, less than 37.84% of C++ online submissions for Squares of a Sorted Array.
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans;
        for(int i = 0; i < A.size(); i++) ans.push_back(A[i] * A[i]);
        sort(ans.begin(), ans.end());
        return ans;
    }
};