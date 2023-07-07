class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int a = 0;
        int d = 0;
        for(auto &it:nums){
            if(it>0) a++;
            if(it<0) d++;
        }
        return max(a,d);
    }
};