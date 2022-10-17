class Solution {
public:
    bool checkIfPangram(string &s) {
        int v[26] = {};
        for(int i = 0;i<s.size();i++){
            v[s[i]-'a']++;
        }
        bool ok = true;
        for(auto &it:v){
            if(it==0) { ok=false;break;}
        }
        return ok;
    }
};