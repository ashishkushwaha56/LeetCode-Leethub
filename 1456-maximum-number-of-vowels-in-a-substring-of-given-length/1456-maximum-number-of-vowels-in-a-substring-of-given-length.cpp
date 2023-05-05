class Solution {
public:
    int maxVowels(string s, int k) {
        int i = 0;
        unordered_map<char,int> mb = {{'a',0},{'e',0},{'i',0},{'o',0},{'u',0}};
        while(i<k){
            if(mb.find(s[i])!=mb.end()) mb[s[i]]++;
            i++;
        }
        int cnt = 0;
        int ans = 0;
        while(i<s.size()){
            cnt=0;
            for(auto &it:mb){
                cnt+=it.second;
            }
            ans = max(ans,cnt);
            if(mb.find(s[i-k])!=mb.end()){
                mb[s[i-k]]--;
            }
            if(mb.find(s[i])!=mb.end()){
                mb[s[i]]++;
            }
            
            
            i++;
            
        }
        cnt = 0;
        for(auto &it:mb){
                cnt+=it.second;
            }
            ans = max(ans,cnt);
        return ans;
    }
};