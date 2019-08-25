class Solution {
public:
    double dist(double x1, double y1, double x2, double y2){
        return sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>> > pq;
        for(int i = 0; i < points.size(); i++){
            double distance = dist(0, 0, points[i][0], points[i][1]);
            pq.push({distance, i});
        }
        vector<vector<int>> ans;
        while(K > 0 && !pq.empty()){
            pair<double, int> pp = pq.top();
            pq.pop();
            int ind = pp.second;
            //cout << ind << " " << pp.first << endl;
            ans.push_back({points[ind][0], points[ind][1]});
            K--;
        }
        
        return ans;
    }
};