class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int,int> mb;
        for(auto &it:nums){
            mb[it]++;
        }
        int ans = 0;
        for(auto &it:mb){
            if(it.second == 1) ans+=(it.first);
        }
        return ans;
    }
};