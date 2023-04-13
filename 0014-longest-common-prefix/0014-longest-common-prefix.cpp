class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int j = 0;
        bool ok = true;
        char c;
        while(true){
            ok = true;
            if(j>=strs[0].size()) {
                break;
            }
            c = strs[0][j];
            for(int i= 1;i<strs.size();i++){
                if(j>=strs[i].size()){
                    ok = false;
                    break;
                }
                else if(strs[i][j]!=c){
                    ok =false;
                    break;
                }
            }
            if(ok){
                ans+=c;
            }
            else {
                break;
            }
            j++;
        }
        return ans;
    }
};