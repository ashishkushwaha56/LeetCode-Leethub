class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while(i<s.size() and j<t.size()){
            while(j<t.size() and i<s.size() and s[i]!=t[j]){
                j++;
            }
            if(s[i]==t[j]){
                i++,j++;
            }
        }
        if(i == s.size()) return true;
        return false;
    }
};