class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int cnt = 0;
        int sum = accumulate(nums.begin(),nums.end(),0ll);
        for(int i = 0;i<nums.size();i++){
            sum-=nums[i];
            if(cnt==sum) return i;
            cnt+=nums[i];
        }
        return -1;
    }
};