class Solution {
public:
    struct Node{
        int node;
        int mask;
        int total_dist;
        Node(int a,int b,int c){
            node = a;
            mask = b;
            total_dist = c;
        }
    };
    int shortestPathLength(vector<vector<int>>& adj) {
        int n = adj.size();
        queue<Node> q;
        int all_mask = (1<<n)-1;
        set<pair<int,int>> s;
        for(int i = 0;i<n;i++){
            Node newnode(i,(1<<i),0);
            q.push(newnode);
            s.insert({i,(1<<i)});
        }

        while(!q.empty()){
            Node temp = q.front();
            q.pop();
            if(temp.mask == all_mask) return temp.total_dist;
            for(auto &it:adj[temp.node]){
                int bothmask = temp.mask;
                bothmask = bothmask|(1<<it);
                Node sd(it,bothmask,temp.total_dist+1);
                if(s.find({it,bothmask})==s.end()){
                    q.push(sd);
                    s.insert({it,bothmask});
                }
            }
        }
        return -1;
    }
};