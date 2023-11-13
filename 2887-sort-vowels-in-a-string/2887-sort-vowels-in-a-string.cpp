class Solution {
public:
    string sortVowels(string s) {
        string d = "";
        set<char> sd = {'a','e','i','o','u','A','E','I','O','U'};
        for(auto &it:s){
            if(sd.find(it)!=sd.end()){
                d+=it;
            }
        }
        sort(d.begin(),d.end());
        int j = 0;
        int i = 0;
        while(i<s.size()){
            if(sd.find(s[i])!=sd.end()){
                s[i] = d[j];
                j++;
            }
            i++;
        }
        return s;
    }
    
};