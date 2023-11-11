class Graph {
public:
    vector<vector<pair<int,int>>> adj; 
    vector<int> vis,cost;

    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto &it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vis.resize(n);
        cost.resize(n);
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        for(int i = 0;i<vis.size();i++){
            vis[i] = 0;
            cost[i] = INT_MAX;
        }
        cost[node1] = 0;
        int current = node1;
 
        // Set of vertices that has
        // a parent (one or more)
        // marked as visited
        unordered_set<int> sett;
        while (true) {
    
            // Mark current as visited
            vis[current] = true;
            for (int i = 0;
                i < adj[current].size();
                i++) {
                int v = adj[current][i].first;
                if (vis[v])
                    continue;
    
                // Inserting into the
                // visited vertex
                sett.insert(v);
                int alt
                    = cost[current]
                    + adj[current][i].second;
    
                // Condition to check the distance
                // is correct and update it
                // if it is minimum from the previous
                // computed distance
                if (alt < cost[v]) {
                    cost[v] = alt;
                    // path[v] = current;
                }
            }
            sett.erase(current);
            if (sett.empty())
                break;
    
            // The new current
            int minDist = INT_MAX;
            int index = 0;
    
            // Loop to update the distance
            // of the vertices of the graph
            for (int a: sett) {
                if (cost[a] < minDist) {
                    minDist = cost[a];
                    index = a;
                }
            }
            current = index;
        }
        // dfs(node1);
        if(cost[node2] == INT_MAX) return -1;
        return cost[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */