class Solution {
public:
    bool areOccurrencesEqual(string s) {
       vector<int> v(26);
       for(int i = 0;i<s.size();i++){
           v[s[i]-'a']++;
       } 
       int last = -1;
       int i = 0;
       while(i<26){
           while(i<26 and v[i] == 0){
               i++;
           }
           if(i<26){
               if(last == -1){
                   last = v[i];
               }
               else {
                   if(last!=v[i]) return false;
               }
               last= v[i];
               i++;
           }
       }
       return true;


    }
};