class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
      unordered_map<int,int> from,to;
        for(int i = 0;i<edges.size();i++){
            from[edges[i][0]]++;
            to[edges[i][1]]++;
        }
        vector<int> ans;
        for(auto &it: from){
            if(to.find(it.first)==to.end())
                ans.push_back(it.first);
        }
        return ans;
    }
};