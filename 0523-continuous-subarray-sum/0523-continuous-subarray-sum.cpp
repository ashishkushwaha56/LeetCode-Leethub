class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for(int i = 0;i<nums.size();i++){
            nums[i] = nums[i]%k;
        }
        if(nums.size()<2){
            return false;
        }
        map<int,int> mb;
        mb[0] = -1;
        mb[nums[0]] = 0;
        int sum = nums[0];
        int l = sum;
        for(int i = 1;i<nums.size();i++){
            // l = sum;
            sum+=nums[i];
            if(mb.find(sum%k)!=mb.end() and i-mb[sum%k]>=2){
                return true;
            }
//             if(l+nums[i] == sum){
                
//             }
            // else{
                mb[sum%k] = i;
            // }
            // for(auto &it:mb){
            //     cout<<it.first<<" "<<it.second<<endl;
            // }
        }
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i] == 0 and nums[i+1] == 0){
                return true;
            }
        }
        return ((sum%k)?false:true);
    }
};