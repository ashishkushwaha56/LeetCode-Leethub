class Solution {
public:
    vector<string> ans;
    void check(int &i,string &s){
        if(i>=s.size()){
            ans.push_back(s);
            return;
        }
        if(s[i]>='0' and s[i]<='9'){
            
            i++;
            check(i,s);
            i--;
        }
        else if(s[i]>='a' and s[i]<='z'){
            s[i] = (s[i]-'a')+'A';
            i++;
            check(i,s);
            i--;
            s[i] = (s[i]-'A')+'a';
            i++;
            check(i,s);
            i--;
        }
    }
    vector<string> letterCasePermutation(string s) {
        for(int i = 0;i<s.size();i++){
            if(s[i]>='A' and s[i]<='Z') s[i] = (s[i]-'A')+'a';
        }
        int i= 0;
        check(i,s);
        return ans;
    }
};