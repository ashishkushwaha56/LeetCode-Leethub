class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        pair<int,int> a[n];
        a[0].first = nums[0];
        a[n-1].second = nums[n-1];
        for(int i = 1;i<n;i++){
            a[i].first = min(nums[i],a[i-1].first);
        }
        for(int i = n-2;i>=0;i--){
            a[i].second = max(nums[i],a[i+1].second);
        }
        for(int i = 1;i<n-1;i++){
            if((a[i-1].first>=nums[i]) or (a[i+1].second<=nums[i])) continue;
            return true;
        }
        return false;
    }
};