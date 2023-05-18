class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        map<int,vector<int>> mb = {{0,{-1}}};
        int l = -1;
        int ans = 0;
        int cnt=  0;
        for(int i = 0;i<nums.size();i++){
            cnt+=nums[i];
            if(mb.find(cnt-target)!=mb.end()){
                auto it = mb.find(cnt-target);
                auto itr = lower_bound((*it).second.begin(),(*it).second.end(),l);
                if(itr!=(*it).second.end()){
                    ans++;
                    l = i;
                }
            }
            mb[cnt].push_back(i);
        }
        return ans;
        
    }
};