class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> mb;
        int cnt = 0;
        for(int i = 0;i<s.size();i++){
            if(mb.find(s[i])!=mb.end()) {
                cnt++;
                mb.clear();
                
            }
            mb[s[i]]++;
        }
        return cnt+1;
    }
};