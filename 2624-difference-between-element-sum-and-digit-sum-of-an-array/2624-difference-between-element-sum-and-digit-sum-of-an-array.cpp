class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int a = 0;
        int d = 0;
        for(auto &it:nums){
            a+=it;
            while(it>0){
                d+=it%10;
                it/=10;
            }
        }
        return abs(a-d);
    }
};