class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> sd;
        set<char> b;
        for(auto &it:allowed){
            sd.insert(it);
        }
        int ans = 0;
        for(int i = 0;i<words.size();i++){
            bool ok = true;
            for(auto &it:words[i]){
                if(sd.find(it)==sd.end()) ok = false;
            }
            ans+=(ok);
        }
        return ans;
    }
};