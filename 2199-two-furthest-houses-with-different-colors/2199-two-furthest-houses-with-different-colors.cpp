class Solution {
public:
    int maxDistance(vector<int>& nums) {
        int ans = 0;
        for(int i = nums.size()-1;i>=1;i--){
            for(int j = 0;j<i;j++){
                if(nums[i]!=nums[j]) ans =max(ans, abs(i-j));
            }
        }
        return ans;
    }
};