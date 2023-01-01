class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<set<string>> v(26);
        string a = "";
        int j = 0;
        // if(pattern.size()==s.size()) return true;
        unordered_map<string,set<char>>mb;
        for(int i = 0;i<s.size();i++){
            if(s[i] == ' '){
                if(j>=pattern.size()) return false;
                v[pattern[j]-'a'].insert(a);
                mb[a].insert(pattern[j]);
                a = "";
                j++;
            }
            else{
                a+=s[i];
            }
        }
        if(j>=pattern.size()) return false;
        v[pattern[j]-'a'].insert(a);
        mb[a].insert(pattern[j]);
        if(j<pattern.size()-1) return false;
        for(auto &it:v){
            if(it.size()>1) return false;
        }
        for(auto &it:mb){
            if(it.second.size()>1) return false;
        }
        return true;
    }
};