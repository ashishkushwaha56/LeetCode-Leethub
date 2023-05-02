class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string d = "";
        set<char> cd(s.begin(),s.end());
        // if((s.size()&1) and s.size()>1){
        //     if(cd.size() == 1) return true;
        //     return false;
        // }
        if(s.size() == 1) return false;
        bool ok = true;
        for(int i = 0;i<s.size()/2;i++){
            d+=s[i];
            
            if(s.size()%d.size() == 0){
                ok = true;
                for(int j = 1;j<s.size()/d.size();j++){
                    for(int k = j*d.size();k<(j+1)*d.size();k++){
                        if(d[k-(j*d.size())]!=s[k]){
                            ok = false;
                            break;
                        }
                    }
                    if(!ok) break;
                }
                if(ok) return true;
            }
        }
        return false;
    }
};