class Solution {
public:
    int minNumberOfFrogs(string s) {
        map<char,int> mb;
        int ans = 0;
        int cnt = 0;
        for(int i = 0;i<s.size();i++){
            cnt = 0;
            if(s[i] == 'c'){
                mb[s[i]]++;
            }
            else if(s[i]=='r'){
                if(mb.find('c')==mb.end()){
                    return -1;
                }
                mb['c']--;
                mb['r']++;
                if(mb['c'] == 0) mb.erase('c');
            }
            else if(s[i]=='o'){
                if(mb.find('r')==mb.end()){
                    return -1;
                }
                mb['r']--;
                mb['o']++;
                if(mb['r'] == 0) mb.erase('r');
            }
            else if(s[i]=='a'){
                if(mb.find('o')==mb.end()){
                    return -1;
                }
                mb['o']--;
                mb['a']++;
                if(mb['o'] == 0) mb.erase('o');
            }
            else if(s[i]=='k'){
                if(mb.find('a')==mb.end()){
                    return -1;
                }
                mb['a']--;
                // mb['k']++;
                if(mb['a'] == 0) mb.erase('a');
            }
            for(auto &it:mb){
                cnt+=it.second;
            }
            ans = max(ans,cnt);
        }
        if(mb.size()>0) return -1;
        return ans;
    }
};