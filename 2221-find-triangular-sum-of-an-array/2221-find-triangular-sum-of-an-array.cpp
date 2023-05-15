class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int a,b,c;
        if(nums.size()==1){
            return nums[0];
        }
        else if(nums.size()==2){
            return (nums[0]+nums[1])%10;
        }
        else{
            int j = nums.size()-1;
            while(j>=0){
                int i = 0;
                a = nums[i];
                while(i<j){
                    // a = nums[i];
                    b = nums[i+1];
                    
                    c = (a+b)%10;
                    a = b;
                    nums[i] = c;
                    i++;
                }
                j--;
            }
            return nums[0];
        }
    }
};