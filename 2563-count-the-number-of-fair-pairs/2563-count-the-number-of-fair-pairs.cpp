class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(),nums.end());
        deque<int> mb;
        for(auto &it:nums){
            mb.push_back(it);
        }
        for(int i  =0 ;i<nums.size();i++){
            mb.pop_front();
            auto it1 = lower_bound(mb.begin(),mb.end(),lower-nums[i]);
            auto it2 = upper_bound(mb.begin(),mb.end(),upper-nums[i]);
            ans+=it2-it1;
        }
        return ans;
    }
};