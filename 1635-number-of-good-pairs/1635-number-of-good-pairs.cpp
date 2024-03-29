class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mb;
        for(auto &it:nums) mb[it]++;
        int ans = 0;
        for(auto &it:mb){
            ans+=((it.second*(it.second-1))/2);
        }
        return ans;
    }
};