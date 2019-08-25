class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if(sticks.size() == 1) return sticks[0];
        if(sticks.size() == 2) return sticks[0] + sticks[1];
        
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq; //MIN heap
        for(int i = 0; i < sticks.size(); i++)
            pq.push(sticks[i]);
        
        while(pq.size() >= 2){
            int num1 = pq.top();
            pq.pop();
            int num2 = pq.top();
            pq.pop();
            ans = ans + num1 + num2;
            pq.push(num1+num2);
        }
        return ans;
    }
};