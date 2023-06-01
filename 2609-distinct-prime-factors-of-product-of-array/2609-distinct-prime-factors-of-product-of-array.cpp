class Solution {
public:
    set<int> ans;
    int distinctPrimeFactors(vector<int>& nums) {
        int d;
        for(auto &it:nums){
            d= it;
            for(int i = 2;i*i<=d;i++){
                if(it%i == 0){
                    while(it%i == 0){
                        it/=i;
                    }
                    ans.insert(i);
                }
            }
            if(it>1){
                ans.insert(it);
            }
        }
        return ans.size();
    }
};