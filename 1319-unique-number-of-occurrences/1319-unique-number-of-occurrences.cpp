class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        set<int> sd;
        unordered_map<int,int> mb;
        for(auto &it:arr){
            mb[it]++;
        }
        for(auto &it:mb){
            if(sd.find(it.second)!=sd.end()) return false;
            sd.insert(it.second);
        }
        return true;
    }
};