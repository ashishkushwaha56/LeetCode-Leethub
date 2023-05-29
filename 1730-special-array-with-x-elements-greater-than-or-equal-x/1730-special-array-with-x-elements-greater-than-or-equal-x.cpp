class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = nums[nums.size()-1];
        while(l<=r){
            int mid = l+(r-l)/2;
            auto it = lower_bound(nums.begin(),nums.end(),mid)-nums.begin();
            it = nums.size()-it;
            if(mid==it){
                return mid;
            }
            else if(it>mid){
                l=mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return -1;
    }
};