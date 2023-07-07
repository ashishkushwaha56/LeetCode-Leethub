class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int ans = 0;
        for(int i = nums.size()-1;i>=3;i--){
            for(int j = i-1;j>=2;j--){
                for(int k = j-1;k>=1;k--){
                    for(int l = k-1;l>=0;l--){
                        if(nums[j]+nums[k]+nums[l] == nums[i]) ans++;
                    }
                }
            }
        }
        return ans;
    }
};