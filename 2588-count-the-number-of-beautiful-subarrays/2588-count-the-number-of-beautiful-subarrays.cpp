class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int,int> mb={{0,1}};
        int cnt = 0;
        for(int i = 0;i<nums.size();i++){
            cnt = (cnt^nums[i]);
            if(mb.find(cnt)!=mb.end()){
                ans+=mb[cnt];
            }
            mb[cnt]++;
        }
        return ans;
    }
};