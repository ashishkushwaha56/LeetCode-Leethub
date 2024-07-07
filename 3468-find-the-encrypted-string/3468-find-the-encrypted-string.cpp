class Solution {
public:
    string getEncryptedString(string s, int k) {
        
        string ans;
        for(int i = 0;i<s.size();i++){
            ans+=(s[(i+k)%s.size()]);
        }
        return ans;
    }
};