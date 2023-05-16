class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        map<int,int> mb;
        for(int i = 0;i<nums.size();i++){
            mb[nums[i]]++;
        }
        sort(nums.rbegin(),nums.rend());
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            auto it = mb.upper_bound(nums[i]);
            if(it != mb.end()){
                ans++;
                mb[(*it).first]--;
                if(mb[(*it).first] == 0){
                    mb.erase((*it).first);
                }
            }
        }
        return ans;
    }
};