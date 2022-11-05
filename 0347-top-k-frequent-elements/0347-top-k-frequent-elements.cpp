class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> vb;
        for(int i= 0;i<nums.size();i++){
            vb[nums[i]]++; 
        }
        vector<pair<int,int>> v;
        for(auto &it:vb){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
           return a.second>b.second; 
        });
        auto i = 0;
        while(k--){
            ans.push_back(v[i].first);
            i++;
        }
        return ans;
    }
};