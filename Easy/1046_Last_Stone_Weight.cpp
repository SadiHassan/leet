class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        for(int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }
        
        while(!pq.empty()){
            if(pq.size() == 1) return pq.top();
            
            int x = pq.top();
            pq.pop();
            
            int y = pq.top();
            pq.pop();
            
            if(x != y) pq.push(abs(x - y));
        }
        
        return 0;
    }
};