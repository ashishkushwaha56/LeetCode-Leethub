class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int neg = 1;
        int pos = 0;
        int i = 0;
        vector<int> ans(nums.size());
        while(i<nums.size()){
            if(nums[i]<0){
                ans[neg] = nums[i];
                neg+=2;
            }
            else {
                ans[pos] = nums[i];
                pos+=2;
            }
            i++;
        }
        return ans;
    }
};