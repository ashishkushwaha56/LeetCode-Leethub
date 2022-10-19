class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mb;
        for(auto &it:words){
            mb[it]++;
        }
        vector<pair<string,int>> v;
        
        for(auto &it:mb){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),[&](pair<string,int>&a,pair<string,int>&b){
           if(a.second == b.second) return a.first<b.first;
            return a.second>b.second;
        });
        vector<string> ans;
        int i = 0;
        while(k){
            ans.push_back(v[i].first);
            k--;
            i++;
        }
        return ans;
    }
};