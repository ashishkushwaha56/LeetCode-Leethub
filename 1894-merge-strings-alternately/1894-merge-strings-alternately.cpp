class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans= "";
        int i = 0,j  =0;
        while(i<word1.size() and j<word2.size()){
            ans+=word1[i];
            ans+=word2[j];
            i++;
            j++;
        }
        while(i<word1.size()){
            ans+=word1[i];
            i++;
        }
        while(j<word2.size()){
            ans+=word2[j];
            j++;
        }
        return ans;
    }
};