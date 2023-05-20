class Solution {
public:
    int n = 10000;
    vector<int> parent;
    vector<int> size;
    void make(int a){
        parent.resize(n,0);
        size.resize(n,0);
        for(int i = 1;i<=a;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int a){
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }

    void _union(int a,int b){
        int u = find(a);
        int v = find(b);
        if(u!=v){
            if(size[u]<size[v])
                swap(u,v);
            parent[v] = u;
            size[u]+=size[v];
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> v;
        for(int i = 0;i<points.size()-1;i++){
            for(int j = i+1;j<points.size();j++){
                v.push_back({i+1,j+1,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
                
            }
        }
        sort(v.begin(),v.end(),[&](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });
        int ans = 0;
        make(points.size());
        for(int i = 0;i<v.size();i++){
            if(find(v[i][0]) == find(v[i][1])) continue;
            _union(v[i][0],v[i][1]);
            ans+=v[i][2];
        }
        return ans;
    }
};