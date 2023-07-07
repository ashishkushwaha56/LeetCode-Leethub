class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        map<int,int> left,right;
        for(auto &it:nums){
            right[it]++;
        }
        vector<int> ans(nums.size());
        for(int i = 0;i<nums.size();i++){
            left[nums[i]]++;
            right[nums[i]]--;
            if(right[nums[i]] == 0) right.erase(nums[i]);
            ans[i] = left.size()-right.size();
        }
        return ans;
    }
};