class Solution {
public:
    bool backspaceCompare(string s, string t) {
       stack<char>s1,s2;
       for(int i = 0;i<s.size();i++){
           if(s1.empty() and s[i]!='#'){
               s1.push(s[i]);
           }
           else{
               if(s[i] == '#' and !s1.empty()){
                   s1.pop();
               }
               else if(s[i]!='#') s1.push(s[i]);
           }
       }
       for(int i = 0;i<t.size();i++){
           if(s2.empty() and t[i]!='#'){
               s2.push(t[i]);
           }
           else{
               if(t[i] == '#' and !s2.empty()){
                   s2.pop();
               }
               else if(t[i]!='#') s2.push(t[i]);
           }
       } 
       return s1==s2;
    }
};