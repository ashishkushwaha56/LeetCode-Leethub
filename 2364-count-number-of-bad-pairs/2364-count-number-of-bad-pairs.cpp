class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int,int> mb;
        for(int i = 0;i<nums.size();i++){
            if(mb.find(nums[i]-i)!=mb.end()){
                ans+=mb[nums[i]-i];
            }
            mb[nums[i]-i]++;
        }
        return ((long long)(nums.size()*(nums.size()-1))/2-ans);
    }
};