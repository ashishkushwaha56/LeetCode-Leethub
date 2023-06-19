class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // vector<vector<int>>first = costs,second = costs;
        vector<pair<int,int>> v;
        for(int i = 0;i<costs.size();i++){
            v.push_back({costs[i][1]-costs[i][0],i});
        }
        sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
            return a.first>b.first;
        });
        int ans = 0;
        for(int i = 0;i<v.size()/2;i++){
            ans+=costs[v[i].second][0];
        }
        for(int i = v.size()/2;i<v.size();i++){
            ans+=costs[v[i].second][1];
        }
        return ans;
    }
};