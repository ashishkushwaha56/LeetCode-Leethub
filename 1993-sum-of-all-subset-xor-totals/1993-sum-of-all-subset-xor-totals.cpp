class Solution {
public:
    int ans = 0;
    void dfs(vector<int>&nums,int i,int cnt){
        if(i == nums.size()) {ans+=cnt;return;}
        dfs(nums,i+1,(cnt^nums[i]));
        dfs(nums,i+1,cnt);
    }
    int subsetXORSum(vector<int>& nums) {
        dfs(nums,0,0);
        return ans;
    }
};