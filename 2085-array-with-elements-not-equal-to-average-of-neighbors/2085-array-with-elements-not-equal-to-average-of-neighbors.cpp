class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        sort(nums.rbegin(),nums.rend());
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            if(ans.size()&1){
                ans.push_back(nums[l]);
                l++;
            }
            else{
                ans.push_back(nums[r]);
                r--;
            }
        }
        return ans;
    }
};