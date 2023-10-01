class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> left_max(nums.size());
        vector<int> right_min(nums.size(),INT_MAX);
        vector<int> right_max(nums.size());
        right_max[nums.size()-1] =nums[nums.size()-1];
        for(int i = nums.size()-2;i>=0;i--){
            right_max[i] = max(right_max[i+1],nums[i]);
            right_min[i] = min(right_min[i+1],nums[i]);
        }
        left_max[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            left_max[i] = max(nums[i],left_max[i-1]);
        }
        long long ans= 0;
        for(int i = nums.size()-2;i>0;i--){
            // if(left_max[i-1]<=right_min[i].first) break;
            ans = max(ans,(long long)(left_max[i-1]-nums[i])*right_max[i+1]);
            
            // cout<<i<<" "<<ans<<endl;
        }
        return ans;
    }
};