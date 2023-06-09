class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l = 0;
        int r=nums.size()-1;
        int cnt = 0;
        while(l<r){
            if(nums[l]+nums[r]==k){
                cnt++;
                l++;r--;
            }
            else if(nums[l]+nums[r]>k){
                r--;
            }
            else{
                l++;
            }
        }
        return cnt;
    }
};