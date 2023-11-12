class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int maxe = -1;
        for(auto &it:routes){
            for(auto &i:it){
                maxe = max(i,maxe);
            }
        }
        if(maxe<target) return -1;
        int n = routes.size();
        vector<int> min_to_reach(maxe+1,INT_MAX);
        min_to_reach[source] = 0;
        bool ok = true;
        while(ok){
            ok = false;
            for(auto &it:routes){
                int mine = n+1;
                for(auto &stop:it){
                    mine= min(mine,min_to_reach[stop]);
                }
                mine++;
                for(auto &stop:it){
                    if(min_to_reach[stop]>mine){
                        min_to_reach[stop] = mine;
                        ok = true;
                    }
                }
            }
        }
        return min_to_reach[target]<n+1?min_to_reach[target]:-1;
    }
};