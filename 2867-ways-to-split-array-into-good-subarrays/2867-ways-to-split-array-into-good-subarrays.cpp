class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int mod = 1e9+7;
        long long ans = 1;
        vector<int> v;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==1) v.push_back(i);
        }
        if(v.size()==0) return 0;
        if(v.size() == 1) return 1;
        for(int i = 0;i<v.size()-1;i++){
            ans = (ans*(v[i+1]-v[i]))%mod;
        }
        return ans;
    }
};