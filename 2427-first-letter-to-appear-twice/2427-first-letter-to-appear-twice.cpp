class Solution {
public:
    char repeatedCharacter(string s) {
        set<char> sd;
        for(auto &it:s){
            if(sd.find(it)!=sd.end()){
                return it;
            }
            sd.insert(it);
        }
        return ';';
    }
};