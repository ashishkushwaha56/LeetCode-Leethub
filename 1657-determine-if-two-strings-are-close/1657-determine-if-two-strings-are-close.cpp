class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int> mb1,mb2;
        for(int i = 0;i<word1.size();i++){
            mb1[word1[i]]++;
        }
        for(int i = 0;i<word2.size();i++){
            mb2[word2[i]]++;
        }
        unordered_map<int,int> cb;
        for(auto &it:mb2){
            cb[it.second]++;
        }
        if(word1.size()!=word2.size()) return false;
        for(auto &it:mb1){
            if(cb.find(it.second)==cb.end()) return false;
            cb[it.second]--;
            if(cb[it.second]==0) cb.erase(it.second);
        }
        unordered_set<char> cv,cn;
        for(int i = 0;i<word2.size();i++){
            cv.insert(word2[i]);
            cn.insert(word1[i]);
        }
        for(auto &it:cn){
            if(cv.find(it)==cv.end()) return false;
        }
        return true;
    }
};