class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        auto it = lower_bound(nums.begin(),nums.end(),0);
        int r = it-nums.begin();
        int l = r-1;
        while(l>=0 and r<n){
            if(nums[l]*nums[l]<nums[r]*nums[r]){
                ans.push_back(nums[l]*nums[l]);
                l--;
            }
            else if(nums[l]*nums[l]>nums[r]*nums[r]){
                ans.push_back(nums[r]*nums[r]);
                r++;
            }
            else{
                ans.push_back(nums[l]*nums[l]);
                ans.push_back(nums[l]*nums[l]);
                l--;
                r++;
            }
        }
        while(l>=0){
            ans.push_back(nums[l]*nums[l]);
            l--;
        }
        while(r<n){
            ans.push_back(nums[r]*nums[r]);
            r++;
        }
        return ans;
    }
};