class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> v(26);
        for(auto &it:words){
            for(auto &i:it){
                v[i-'a']++;
            }
        }
        for(int i = 0;i<v.size();i++){
            if(v[i]%words.size()!=0) return false;
        }
        return true;
    }
};