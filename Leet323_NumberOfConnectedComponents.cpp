#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int find_parent(int child, vector<int>& parents){
        if(child == parents[child])
            return child;
        return parents[child] = find_parent(parents[child], parents);
    }

    int getComponents(vector< vector<int> > edges, int N){

        vector<int> parents(N);
        for(int i = 0; i < N; i++)
            parents[i] = i;

        for(int i = 0; i < edges.size(); i++){
            int u = find_parent(edges[i][0], parents);
            int v = find_parent(edges[i][1], parents);

            if(u != v){
                parents[u] = v;
                N--;
            }
        }
        return N;
    }
};


int main(){
    Solution* p = new Solution();

    vector< vector <int> > edges;

    vector <int> a0;
    a0.push_back(0);
    a0.push_back(1);

    vector <int> a1;
    a1.push_back(1);
    a1.push_back(2);

    vector <int> a2;
    a2.push_back(3);
    a2.push_back(4);

    vector <int> a3;
    a3.push_back(4);
    a3.push_back(5);

    vector <int> a4;
    a4.push_back(5);
    a4.push_back(3);

    edges.push_back(a0);
    edges.push_back(a1);
    edges.push_back(a2);
    edges.push_back(a3);
    edges.push_back(a4);

    cout << p->getComponents(edges, 6) << endl;

return 0;
}
