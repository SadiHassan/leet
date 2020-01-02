#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector< vector<int> > criticalConnections(int n, vector< vector<int> >& connections) {
        vector< vector<int> > edges(n,vector<int>());
        vector< vector<int> > res;
        vector<int> dfn(n, 0); //discovery value
        vector<int> low(n, INT_MAX);
        vector<int> parent(n, -1);
        int time = 1;
        for(int i = 0; i < connections.size(); i++)
        {
            edges[connections[i][0]].push_back(connections[i][1]);
            edges[connections[i][1]].push_back(connections[i][0]);
        }
        for(int u = 0; u < n; u++)
        {
            if(dfn[u] == 0)
                tarjan(u,time,dfn,low,parent,edges,res);
        }
        return res;
    }
private:
    void tarjan(int u, int &time, vector<int> &dfn, vector<int> &low, vector<int> &parent, vector< vector<int> > &edges, vector< vector<int> > &res)
    {
        cout <<"u: "<< u << " time: " << time << " low[u]: " << low[u] << endl;
        dfn[u] = time;
        low[u] = time;
        time++;

        for(int v:edges[u])
        {
            if(dfn[v] == 0)
            {
                parent[v] = u;
                tarjan(v, time, dfn, low, parent, edges, res);
                low[u] = min(low[u], low[v]);
                if(low[v] > dfn[u])
                {
                    //cout << "Edges---> u: " << u << " v: " << v << "  dfn[v]: " << dfn[v] << "  low[v]: " << low[v] << "  dfn[u]: " << dfn[u] << "  low[u]: " << low[u] << endl;
                    vector<int> tmp = {u,v};
                    res.push_back(tmp);
                }
            }
            else if(v != parent[u])
            {
                low[u] = min(low[u],dfn[v]);
            }
        }
        cout <<"u: "<< u << " time: " << time << " low[u]: " << low[u] << endl << endl;
        return;
    }
};
vector<int> add_edge(int u, int v){
    vector<int> edge;
    edge.push_back(u);
    edge.push_back(v);
    return edge;
}
int main(){

Solution* p;
vector< vector<int> > input;

input.push_back(add_edge(0, 1));
input.push_back(add_edge(1, 2));
input.push_back(add_edge(2, 0));
input.push_back(add_edge(1, 3));

vector< vector<int> > ans = p->criticalConnections(4, input );
for(int i = 0; i < ans.size(); i++)
    cout << ans[i][0] << " " << ans[i][1] << endl;
return 0;
}
