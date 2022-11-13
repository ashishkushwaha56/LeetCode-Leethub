class Solution {
public:
    string reverseWords(string s) {
        vector<string> vb;
        string a = "";
        for(int i = 0;i<s.size();i++){
            if(s[i] == ' '){
                if(!a.empty()){
                    vb.push_back(a);
                    
                }
                a = "";
            }
            else{
                a+=s[i];
            }
        }
        if(!a.empty()){
            vb.push_back(a);
        }
        string ans = "";
        for(int i = vb.size()-1;i>=0;i--){
            ans+=vb[i];
            if(i>0) ans+=' ';
        }
        return ans;
    }
};