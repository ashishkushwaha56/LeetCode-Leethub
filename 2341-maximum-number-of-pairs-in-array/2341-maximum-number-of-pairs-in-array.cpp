class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int v[101] = {};
        int ans = 0;
        int count = 0;
        for(int i = 0;i<nums.size();i++){
            v[nums[i]]++;
        }
        for(int i = 0;i<101;i++){
            ans+=(v[i]/2);
            count+=(v[i]%2);
        }
        return {ans,count};
    }
    
};