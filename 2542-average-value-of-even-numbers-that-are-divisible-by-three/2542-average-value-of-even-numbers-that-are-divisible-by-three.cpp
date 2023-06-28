class Solution {
public:
    int averageValue(vector<int>& nums) {
        int cnt =0;
        int sum=0;
        for(auto &it:nums){
            if(!(it&1) and it%3 == 0) {sum+=it;cnt++;}
        }
        if(cnt == 0) return 0;
        return (sum/cnt);
    }
};