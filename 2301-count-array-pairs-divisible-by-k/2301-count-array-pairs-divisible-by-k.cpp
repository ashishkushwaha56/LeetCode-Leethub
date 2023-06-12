class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<long long,int> mb;
        long long d;
        for(int i = 0;i<nums.size();i++){
            d = __gcd(k,nums[i]);
            for(auto &it:mb){
                if((d*it.first)%k == 0){
                    ans+=it.second;
                }
            }
            mb[d]++;
        } 
        return ans;
    }
};