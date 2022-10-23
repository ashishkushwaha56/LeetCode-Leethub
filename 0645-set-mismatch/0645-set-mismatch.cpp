class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans(2),v(nums.size());
        for(auto &it: nums){
            v[it-1]++;
        }
        for(int i = 0;i<nums.size();i++){
            if(v[i] == 2){
                ans[0] = i+1;
            }
            if(v[i] == 0){
                ans[1]=i+1;
            }
        }
        return ans;
    }
};