class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if(nums.size()==3) return 0;
        sort(nums.begin(),nums.end());
        // for(auto &it:nums){
        //     cout<<it<<" ";   
        // }
        // cout<<endl;
        // int a = (nums[0]+nums[nums.size()-1])/2;
        // nums[0] = a;
        // nums[nums.size()-1] = a;
        // sort(nums.begin(),nums.end());
        // // int ans =0;
        // // for(int i = 0;i<nums.size()-1;i++){
        // //     ans = max(ans,nums[i+1]-nums[i]);
        // // }
        // return nums[nums.size()-1]-nums[0];
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            // cout<<ans<<endl;
            if(i == 0){
                ans = abs(nums[0]-nums[nums.size()-3]);
            }
            else if(i==1){
                ans = min(ans,abs(nums[1]-nums[nums.size()-2]));
                if(nums.size()-i-1>=2){
                    ans = min(ans,abs(nums[0]-nums[nums.size()-3]));
                }
            }
            else if(i>1 or i<nums.size()-2){
                ans = min(ans,abs(nums[2]-nums[nums.size()-1]));
                ans = min(ans,abs(nums[1]-nums[nums.size()-2]));
                ans = min(ans,abs(nums[0]-nums[nums.size()-3]));
            }
            else if(i == nums.size()-2){
                ans = min(ans,abs(nums[1]-nums[nums.size()-2]));
                // if(nums.size()-i-1>=2){
                //     ans = min(ans,abs(nums[1]-nums[nums.size()-3]));
                // }
            }
            else if(i==nums.size()-1){
                ans = min(ans,abs(nums[2]-nums[i]));
            }
        }
        return ans;
    }
};