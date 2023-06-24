class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int mod = 1e9+7;
        int rev;
        int d;
        for(int i=0;i<nums.size();i++){
            rev = 0;
            d = nums[i];
            while(d>0){
                rev = rev*10+d%10;
                d/=10;
            }
            nums[i]=nums[i]-rev;
        }
        unordered_map<int,int> mb;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            if(mb.find(nums[i])!=mb.end()){
                ans=(ans+mb[nums[i]])%mod;
            }
            mb[nums[i]]++;
        }
        return ans;
    }
};