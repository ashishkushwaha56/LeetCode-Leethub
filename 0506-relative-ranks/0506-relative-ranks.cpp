class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.rbegin(),temp.rend());
        unordered_map<int,int> mb;
        for(int i = 0;i<temp.size();i++){
            mb[temp[i]] = i+1;
        }
        vector<string> ans(nums.size());
        string a;
        for(int i = 0;i<nums.size();i++){
            if(mb[nums[i]]==1){
                a = "Gold Medal";
            }
            else if(mb[nums[i]] == 2){
                a = "Silver Medal";
            }
            else if(mb[nums[i]] == 3){
                a = "Bronze Medal";
            }
            else a = to_string(mb[nums[i]]);
            ans[i] = a;
        }
        return ans;
    }
};