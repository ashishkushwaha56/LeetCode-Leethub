class Solution {
public:
    int maxSum(vector<int>& nums) {
        map<char,vector<int>> mb;
        string a;
        for(auto &it:nums){
            a = to_string(it);
            mb[*max_element(a.begin(),a.end())].push_back(it);
        }
        int ans = -1;
        for(auto &it:mb){
            if(it.second.size()>1){
                sort(it.second.rbegin(),it.second.rend());
                ans = max(ans,it.second[0]+it.second[1]);
            }
        }
        return ans;
    }
};