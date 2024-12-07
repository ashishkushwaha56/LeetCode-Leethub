class Solution {
public:
    bool helper(vector<int>& nums, int mid, int maxOperations){
        int32_t opDone = 0;
        for (auto &i: nums){
            if (i > mid){
                opDone += (i / mid) + (i % mid > 0) - 1;
            }
        }
        return opDone <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int32_t low = 1, high = *max_element(nums.begin(),nums.end());
        int32_t ans = -1;
        while (low <= high) {
            int32_t mid = low + (high - low)/2;
            if (helper(nums, mid, maxOperations)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};