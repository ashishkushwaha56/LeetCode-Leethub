class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> sd;
        for(int i=0;i<names.size();i++){
            sd[heights[i]] = names[i];
        }
        vector<string> ans(names.size());
        auto it = sd.end();
        it--;
        for(int i = 0;i<names.size();i++){
            ans[i] = (*it).second;
            it--;
        }
        return ans;
    }
};