class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> mb;
        for(auto &it: nums){
            if(!(it&1))
                mb[it]++;
        }
        vector<pair<int,int>> v;
        for(auto &it:mb){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
           if(a.second == b.second) return a.first<b.first;
            return a.second>b.second;
        });
        if(v.empty())
            return -1;
        return v[0].first;
    }
};