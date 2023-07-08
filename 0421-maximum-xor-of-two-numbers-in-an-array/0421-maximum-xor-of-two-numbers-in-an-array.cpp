class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        unordered_set<int> sd;
        int ans=0;
        int d = 0;
        for(int  i =31;i>=0;i--){
            d = d|(1ll<<i);
            int temp = ans|(1ll<<i);
            for(int j = 0;j<nums.size();j++){
                int a = nums[j]&d;
                if(sd.find(a^temp)!=sd.end()){
                    ans = temp;
                    break;
                }
                sd.insert(a);
            }
            sd.clear();
        }
        return ans;

    }
};