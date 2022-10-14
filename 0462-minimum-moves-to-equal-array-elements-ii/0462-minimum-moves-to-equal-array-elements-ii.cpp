class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mid = n/2;
        int c1 = 0;
        int c2 = INT_MAX;
        int c3 = INT_MAX;
        for(int i = 0;i<n;i++){
            c1+=abs(nums[mid]-nums[i]);
        }
        return c1;
    }
};