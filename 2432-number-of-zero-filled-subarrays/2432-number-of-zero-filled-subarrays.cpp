class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long cnt =0 ;
        for(auto &it:nums){
            if(it == 0){
                cnt++;
            }
            else{
                ans+=((cnt)*(cnt+1))/2;
                cnt=0;
            }
        }
        ans+=((cnt)*(cnt+1))/2;
        return ans;
    }
};