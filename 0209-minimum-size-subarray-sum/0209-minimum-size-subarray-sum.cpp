class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        map<int,int> mb;
        int sum = 0;
        mb[0] = -1;
        int ans = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>=target){
                auto it = mb.lower_bound(sum-target);
                if(sum-target != (*it).first){
                    it--;
                }
                ans = min(ans,i-(*it).second);
            }
            mb[sum] = i;
        }
        if(ans == INT_MAX)return 0;
        return ans;
    }
};