class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt1 = 0;
        int cnt2 = 0;
        unordered_set<char> res = {'a','e','i','o','u','A','E','I','O','U'};
        for(int i =0;i<s.size()/2;i++){
            if(res.find(s[i])!=res.end()) cnt1++;
        }
        
        for(int i =s.size()/2;i<s.size();i++){
            if(res.find(s[i])!=res.end()) cnt2++;
        }
        return cnt1==cnt2;
    }
};