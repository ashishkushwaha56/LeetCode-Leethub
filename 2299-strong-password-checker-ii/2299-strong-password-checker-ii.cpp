class Solution {
public:
    bool strongPasswordCheckerII(string &p) {
       bool arr[4] = {false,false,false,false};
        if(p.size()<8) return false;
        char last_char = p[0];
        string s = "!@#$%^&*()-+";
        auto check = [&](char c,bool *b){
            for(int i = 0;i<s.size();i++){
                if(c == s[i])
                {    
                    *b = true;
                    break;
                }
            }
        };
        for(int i = 0;i<p.size();i++){
            if(p[i]>='a' and p[i]<='z') arr[0]=true;
            if(p[i]>='A' and p[i]<='Z') arr[1]=true;
            if(p[i]>='0' and p[i]<='9') arr[2]=true;
            check(p[i],&arr[3]);
            if(i == 0) continue;
            if(p[i] == last_char) return false;
            last_char = p[i];
        }
        for(int i = 0;i<4;i++){
            if(!arr[i])
                return false;
        }
        return true;
    }
};