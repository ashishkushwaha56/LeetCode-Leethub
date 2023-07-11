class Solution {
public:
    long long countVowels(string s) {
        long long ans = 0;
        set<char> sd = {'a','e','i','o','u'};
        for(int i = 0;i<s.size();i++){
            if(sd.find(s[i])!=sd.end()){
                ans+=(i+1)*(s.size()-i);
            }
        }
        return ans;
    }
};