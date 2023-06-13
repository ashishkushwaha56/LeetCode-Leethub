class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 1;
        int mine = INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1])mine =nums[i];
            else{
                if(nums[i+1]<mine){
                    nums[i+1] = nums[i];
                }
                cnt--;
            }
        }
        return cnt>=0;
    }
};