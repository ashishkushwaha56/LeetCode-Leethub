class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        int cnt0 = 0;
        int prod = 1;
        int prod1 = 1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0) {
                cnt0++;
            }
            if(nums[i]!=0){
                prod1*=nums[i];
            }
                prod*=nums[i];
        }
        
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0 and cnt0 == 1){
                ans[i] = prod1;
            }
            else if(nums[i] == 0 and cnt0>1){
                ans[i] = prod;
            }
            else{
                ans[i] = prod/nums[i];
            }
        }
        return ans;
    }
};