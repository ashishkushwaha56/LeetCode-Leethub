class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       int sum = 0;
       map<int,int> mb;
       mb[0] = 1;
       int ans = 0;
       for(int i = 0;i<nums.size();i++){
        sum+=nums[i];
        int d = sum%k;
        if(d<0){
            d+=k;
        }
        if(mb.find(d)!=mb.end()){
            ans += mb[d];
        }
        mb[d]++;
       } 
       return ans;
    }
};