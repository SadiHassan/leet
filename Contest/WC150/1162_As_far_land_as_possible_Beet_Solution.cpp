class Solution {
  template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
  template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

public:
  int maxDistance(vector<vector<int>>& grid) {
    int n=grid.size();
    int h=n,w=n;
    vector<vector<int> > dp(h,vector<int>(w,-1));
    using P = pair<int, int>;
    queue<P> q;

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(grid[i][j]==1){
          dp[i][j]=0;
          q.emplace(i,j);
        }
      }
    }

    const int dir=4;
    int dy[]={1,-1,0,0,1,1,-1,-1};
    int dx[]={0,0,1,-1,1,-1,1,-1};
    auto in=[&](int y,int x){return 0<=y&&y<h&&0<=x&&x<w;};
    while(!q.empty()){
      int y,x;
      tie(y,x)=q.front();q.pop();
      for(int k=0;k<dir;k++){
        int ny=y+dy[k],nx=x+dx[k];
        if(!in(ny,nx)) continue;
        if(~dp[ny][nx]) continue;
        dp[ny][nx]=dp[y][x]+1;
        q.emplace(ny,nx);
      }
    }

    int ans=0;
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        chmax(ans,dp[i][j]);
    if(ans==0) ans=-1;
    return ans;
  }
};