class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long cnt = 0;
        int ans = 0;
        int i = 0;
        while(i<nums.size() and cnt<n){
            if(nums[i]<=cnt+1){
                cnt+=(nums[i]);
                i++;
            }
            else{
                ans++;
                cnt+=(cnt+1);
            }
        } 
        while(cnt<n){
            cnt+=(cnt+1);
            ans++;
        }
        return ans;
    }
};