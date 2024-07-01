class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int j = 0;
        while(i<s.size() and j<t.size()){
            if(s[i] ==t[j]){
                j++;
                i++;
            }
            else{
                i++;
            }
        }
        return t.size()-j;
    }
};