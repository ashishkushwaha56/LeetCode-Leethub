class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());
        if(nums == temp) return 0;
        int l = 0;
        for(int i = 0;i<temp.size();i++){
            if(nums[i]!=temp[i]){
                l = i;
                break;
            }
        }
        int r = nums.size()-1;
        for(int i = temp.size()-1;i>=0;i--){
            if(nums[i]!=temp[i]){
                r = i;
                break;
            }
        }
        return (r-l+1);
    }
};