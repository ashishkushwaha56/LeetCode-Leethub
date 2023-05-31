class Solution {
public:
    int mod = 1e9+7;
    long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = (binpow(a, b / 2))%mod;
    if (b % 2)
        return (res * (res * a)%mod)%mod;
    else
        return (res * (res)%mod)%mod;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = nums.size()-1;
        int ans = 0;
        while(l<=r and nums[l]+nums[r]>target){
            r--;
        }
        while(l<=r){
            // cout<<r-l<<endl;
            ans=(ans+(binpow(2,r-l)))%mod;
            l++;
            while(l<=r and nums[l]+nums[r]>target){
                r--;
            }
        }
        return ans;
    }
};