class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i = 0;int j = 0;
        long long ans = 0;
        long long sum =0;
        while(i<nums.size()){
            while(j<nums.size() and ((sum+nums[j])*(j-i+1))<k){
                sum+=nums[j];
                j++;
            }
            ans+=(j-i);
            sum-=nums[i];
            i++;
        }
        return ans;
    }
};