class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mb;
        for(auto &it:nums){
            mb[it]++;
        }
        vector<pair<int,int>> v;
        for(auto &it:mb){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
           return a.second>b.second; 
        });
        return v[0].first;
    }
};