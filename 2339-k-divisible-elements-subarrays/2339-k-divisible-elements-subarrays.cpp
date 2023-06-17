class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        map<vector<int>,int> mb;
        int ans = 0;
        int cnt = 0;
        vector<int> temp;
        for(int i = 0;i<nums.size();i++){
            cnt = 0;
            temp.clear();
            for(int j = i;j<nums.size();j++){
                temp.push_back(nums[j]);
                if(nums[j]%p == 0){
                    cnt++;
                }
                if(cnt<=k and mb.find(temp)==mb.end()){
                    mb[temp]++;
                    ans++;
                }
                if(cnt>k) break;
            }
        }
        return ans;
    }
};