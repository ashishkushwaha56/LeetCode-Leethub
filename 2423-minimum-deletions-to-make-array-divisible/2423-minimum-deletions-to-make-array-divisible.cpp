class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd = 0;
        for(int i = 0;i<numsDivide.size();i++){
            gcd = __gcd(gcd,numsDivide[i]);
        }
        sort(nums.begin(),nums.end());
        if(gcd==1 and nums[0]!=1) return -1;
        if(gcd == 1 and nums[0] == 1) return 0;
        int i = 0;
        while(i<nums.size() and gcd%nums[i]>0){
            i++;
        }
        if(i==nums.size()) return -1;
        return i;
    }
};