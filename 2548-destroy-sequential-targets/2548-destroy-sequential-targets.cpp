class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int> mb;
        sort(nums.begin(),nums.end());
        // vector<int> cd(nums.size());
        for(int i = 0;i<nums.size();i++){
            mb[(nums[i]%space)]++;
            // cd[i] = (nums[i]%space);
        }
        int maxval =0;
        // int id = -1;
        for(auto &it:mb){
            if(it.second>maxval){
                maxval=it.second;
                // id = it.first;
            }
        }
        unordered_map<int,int> vb;
        for(auto &it:mb){
            if(it.second == maxval){
                vb[it.first] = it.second;
            }
        }

        for(int i = 0;i<nums.size();i++){
            if(vb.find(nums[i]%space)!=vb.end()){
                return nums[i];
            }
        }
        return 0;

    }
};