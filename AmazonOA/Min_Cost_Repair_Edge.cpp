/*
Min Cost to repair edge

There's an undirected connected graph with n nodes labeled 1..n. But some of the edges has been broken disconnecting the graph. Find the minimum cost to repair the edges so that all the nodes are once again accessible from each other.

Input:

n, an int representing the total number of nodes.
edges, a list of integer pair representing the nodes connected by an edge.
edgesToRepair, a list where each element is a triplet representing the pair of nodes between which an edge is currently broken and the cost of repearing that edge, respectively (e.g. [1, 2, 12] means to repear an edge between nodes 1 and 2, the cost would be 12).
Example 1:

Input: n = 5, edges = [[1, 2], [2, 3], [3, 4], [4, 5], [1, 5]], edgesToRepair = [[1, 2, 12], [3, 4, 30], [1, 5, 8]]
Output: 20
Explanation:
There are 3 connected components due to broken edges: [1], [2, 3] and [4, 5].
We can connect these components into a single component by repearing the edges between nodes 1 and 2, and nodes 1 and 5 at a minimum cost 12 + 8 = 20.
Example 2:

Input: n = 6, edges = [[1, 2], [2, 3], [4, 5], [3, 5], [1, 6], [2, 4]], edgesToRepair = [[1, 6, 410], [2, 4, 800]]
Output: 410
Example 3:

Input: n = 6, edges = [[1, 2], [2, 3], [4, 5], [5, 6], [1, 5], [2, 4], [3, 4]], edgesToRepair = [[1, 5, 110], [2, 4, 84], [3, 4, 79]]
Output: 79
*/

/*
Below solution is for similar problem that uses MST Kruskal's algorithm.

To implement the original problem, input need to be prepared a bit.

Firstly, for edges vecotr, keep the first element smaller in each small vectors. Then sort the entire vector from ascending.
Secondly, do the similar thing for the edgesToRepair vector

Now, take another vector and merge the two vectors above in it. For the edges vector, if the edge is not present in edgesToRepair, 
give 0 as weight.

Then apply kruskals in the final vector.
*/



class Solution {
public:
    vector<int> parent;
    
    static bool comp(const vector<int>& a, const vector<int>& b){
        return (a[2] < b[2]);
    }
    
    int find_parent(int a){
        if(a != parent[a])
            parent[a] = find_parent(parent[a]);
        return parent[a];
    }
    
    int minimumCost(int N, vector<vector<int>>& connections) {
        
        sort(connections.begin(), connections.end(), comp);
        
        //IMPORTANT!!! i should start from 0, and go upto N 
        
        for (int i = 0; i <= N; i++) {
            parent.push_back(i);
        }
        
        int total_cost = 0;
        int total_edge = 0;
        
        for(int i = 0; i < connections.size(); i++){
            
            int a = connections[i][0];
            int b = connections[i][1];
            
            int a_p = find_parent(a);
            int b_p = find_parent(b);
            
            if( a_p != b_p){
                total_cost += connections[i][2];
                total_edge++;
                parent[a_p] = b_p;
            }
            if(total_edge == N - 1) return total_cost;
        }
        
        return -1;
    }
    
};

