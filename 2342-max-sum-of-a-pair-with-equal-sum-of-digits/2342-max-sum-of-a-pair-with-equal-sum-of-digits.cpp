class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<multiset<int>> v(85);
        int c = 0;
        int t ;
        for(int i = 0;i<nums.size();i++){
            c = 0;
            t = nums[i];
            while(t){
                c+=(t%10);
                t/=10;
            }
            v[c].insert(nums[i]);
            if(v[c].size()>2){
                auto it = v[c].begin();
                v[c].erase(it);
            }
        }
        int ans = INT_MIN;
        for(int i = 0;i<v.size();i++){
            if(v[i].size()==2){
                auto it = v[i].begin();
                auto it1 = it;
                it1++;
                ans = max(ans,*it+*it1);
            }
        }
        if(ans == INT_MIN) return -1;
        return ans;
    }
};