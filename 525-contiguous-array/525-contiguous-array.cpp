class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mb;
        int s = 0;
        mb[0] = -1;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            s+=nums[i] == 1?1:-1;
            if(mb.find(s)!=mb.end()){
                ans = max(ans,i-mb[s]);
            }
            else{
                mb[s] = i;
            }
        }
        return ans;
    }
};