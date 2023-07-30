class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> v(nums.size());
        int maxe = nums[nums.size()-1];
        for(int i = nums.size()-1;i>=0;i--){
            maxe = max(maxe,nums[i]);
            v[i] = maxe;
        } 
        int ans = 0;
        function <int(int)> helper = [&](int i)->int{
            int l = i;
            int r = nums.size()-1;
            int ans = l;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(v[mid]>=nums[i]){
                    ans = mid;
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            return ans;
        };
        for(int i = 0;i<nums.size();i++){
            ans = max(ans,helper(i)-i);
        }
        return ans;
    }
};