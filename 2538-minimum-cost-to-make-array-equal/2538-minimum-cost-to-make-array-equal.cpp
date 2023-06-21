class Solution {
public:
    long long check(vector<int>&nums,vector<int>&cost,long long x){
        long long res = 0;
        for(int i = 0;i<nums.size();i++){
            res+=abs(nums[i]-x)*cost[i];
        }
        return res;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans = 0;
        long long l = *min_element(nums.begin(),nums.end());
        long long r = *max_element(nums.begin(),nums.end());
        while(l<r){
            long long mid = l+(r-l)/2;
            long long a = check(nums,cost,mid);
            long long b = check(nums,cost,mid+1);
            if(a<b){
                r = mid;
                ans =a;
            }
            else{
                l = mid+1;
                ans = b;
            }
        }
        return ans;
    }
};