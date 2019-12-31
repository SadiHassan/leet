int Solution::solve(vector<int> &A) {
    
    priority_queue<int> q;
    
    for(int i = 0; i < A.size(); i++)
        q.push(A[i] * (-1));
    int ans = 0;
    while(q.size() > 1){
        int x = q.top() * (-1); q.pop();
        int y = 0;
        if(q.size() > 0){
            y = q.top() * (-1); q.pop();    
        }
        //cout << x << " " << y << " " << x + y << endl;
        ans += (x + y);
        q.push((-1) * (x + y));
    }
    return ans;
}