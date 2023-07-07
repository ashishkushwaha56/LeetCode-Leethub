class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> v1(26),b(26);
        for(auto &it:word1){
            v1[it-'a']++;
            
        }
        for(auto &it:word2){
            b[it-'a']++;
            
        }
        
        for(int i = 0;i<26;i++){
            if(abs(v1[i]-b[i])>3) return false;
        }
        return true;
    }
};