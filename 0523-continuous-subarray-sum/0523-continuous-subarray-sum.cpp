class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for(int i = 0;i<nums.size(); i++){
            nums[i] = nums[i]%k;
        }
        unordered_map<int,int> mb;
        mb[0] = -1;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum = (sum+nums[i]);
            if(mb.find(sum%k) == mb.end()){
                mb[sum%k] = i;
            }
            else{
                if(i-mb[sum%k]>=2){
                    return true;
                }
            }
        }
        return (sum%k == 0 and sum!=0)?true:false;
    }
};