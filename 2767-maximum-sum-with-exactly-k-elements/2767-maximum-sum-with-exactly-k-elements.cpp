class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int d = *max_element(nums.begin(),nums.end());
        return (d*k+(k*(k-1))/2);
    }
};