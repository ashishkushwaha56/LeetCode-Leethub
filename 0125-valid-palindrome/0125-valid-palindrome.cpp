class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        // cout<<j<<endl;
        unordered_set<char> sd;
        for(int i = 0;i<26;i++){
            sd.insert(i+'a');
            sd.insert(i+'A');
            if(i<10){
                sd.insert(i+'0');
            }
        }
        
        while(i<j){
            while(j>i and sd.find(s[j]) == sd.end()) j--;
            while(i<j and sd.find(s[i]) == sd.end()) i++;
            if(i==j) break;
            if(s[i]>='A' and s[i]<='Z') s[i] = (s[i]-'A')+'a';
            if(s[j]>='A' and s[j]<='Z') s[j] = (s[j]-'A')+'a';
            // cout<<i<<" "<<j<<endl;
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};