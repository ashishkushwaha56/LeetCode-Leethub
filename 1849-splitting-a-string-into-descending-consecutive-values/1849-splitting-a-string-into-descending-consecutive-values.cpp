class Solution {
public:
    bool f(unsigned long long cnt, string s){
        if(s.empty()) return true;
        for(int i = 0;i<s.size();i++){
            if(stoull(s.substr(0,i+1)) == cnt-1){
                if(f(cnt-1,s.substr(i+1))) return true;
            }
        }
        return false;
    }
    bool splitString(string s) {
        for(int i = 0;i<s.size()-1;i++){
            if(f(stoull(s.substr(0,i+1)),s.substr(i+1))) return true;
        }
        return false;
    }
};