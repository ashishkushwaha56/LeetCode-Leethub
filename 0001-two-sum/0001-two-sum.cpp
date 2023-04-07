class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<int,int> mb;
        // for(int i = 0;i<nums.size();i++){
        //     mb[nums[i]] = i;
        // }
        for(int i= 0;i<nums.size();i++){
            if(mb.find(target-nums[i])!=mb.end()){
                return {i,mb[target-nums[i]]};
            }
            mb[nums[i]] = i;
        }
        return {};
    }
};