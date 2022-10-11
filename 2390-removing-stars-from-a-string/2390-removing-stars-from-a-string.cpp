class Solution {
public:
    string removeStars(string s) {
       stack<char> ans;
       for(int i = 0;i<s.size();i++){
           if(s[i] == '*') ans.pop();
           else ans.push(s[i]);
       }
        string res = "";
        while(!ans.empty()){
            res+=ans.top(),ans.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};