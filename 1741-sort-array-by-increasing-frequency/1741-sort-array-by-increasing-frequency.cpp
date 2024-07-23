class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mb;
        for(auto &it:nums){
            mb[it]++;
        }
        vector<pair<int,int>> sd;
        for(auto &it:mb){
            sd.push_back({it.first,it.second});
        }
        sort(sd.begin(),sd.end(),[&](pair<int,int>&a,pair<int,int>&b){
            if(a.second==b.second){
                return a.first>b.first;
            }
            return a.second<b.second;
        });
        vector<int> v;
        for(auto &it:sd){
            int i = 0;
            while(i<it.second){
                v.push_back(it.first);
                i++;
            }
        }
        return v;
    }
};