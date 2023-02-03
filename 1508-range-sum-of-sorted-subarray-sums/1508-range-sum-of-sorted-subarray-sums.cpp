class Solution {
public:
    const int mod = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> v(nums.begin(),nums.end());
        int sum = 0;
        for(int i = 0;i<nums.size()-1;i++){
            sum = nums[i];
            for(int j = i+1;j<nums.size();j++){
                sum+=nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(),v.end());
        return accumulate(v.begin()+left-1,v.begin()+right,0LL)%mod;
    }
};