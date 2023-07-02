class Solution {
public:
    int ans = 0;
    void dfs(vector<vector<int>>&v,vector<int>&nodes,int i,int cnt){
        if(i == v.size()){
            bool ok = true;
            for(int j = 0;j<nodes.size();j++){
                if(nodes[j]!=0){
                    ok = false;
                    break;
                }
            }
            if(ok){
                ans= max(ans,cnt);
            }
            return;
        }

        // taking the ith request
        nodes[v[i][0]]--;
        nodes[v[i][1]]++;
        dfs(v,nodes,i+1,cnt+1);
        
        // Backtrack
        nodes[v[i][0]]++;
        nodes[v[i][1]]--;

        // not taking the ith request
        dfs(v,nodes,i+1,cnt);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> nodes(n);
        dfs(requests,nodes,0,0);
        return ans;
    }
};