class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        unordered_map<int,int> mb;
        for(auto &it:nums){
            mb[it]++;
        }
        sort(nums.begin(),nums.end());
        for(auto &it:nums){
            if(mb[it]>0){
                int j = 1;
                int d = it+1;
                mb[it]--;
                while(j<k){
                    if(mb[d]==0) return false;
                    mb[d]--;
                    j++;
                    d++;
                }
            }
        }
        return true;
    }
};