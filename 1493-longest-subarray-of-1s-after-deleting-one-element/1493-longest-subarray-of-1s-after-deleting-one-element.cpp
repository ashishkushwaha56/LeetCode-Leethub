class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int last_0 = -1;
        bool ok = nums[0] == 0?true:false;
        if(nums[0] == 0) last_0 = 0;
        int ans = 0;
        int ct =0;
        for(int i = 1;i<n;i++){
            // cout<<l<<" "<<i<<endl;
            if(nums[i] == 0){
                if(ok){
                    l = last_0+1;
                    last_0 = i;
                }
                else{
                    ok = true;
                    last_0 = i;
                }
            }
           ans = max(ans,i-l);
        }
        if(ans == n){
            return ans-1;
        }
        return ans;
    }
};