class Solution {
public:
    string arrangeWords(string text) {
        map<int,vector<string>> mb;
        string s = "";
        for(int i = 0;i<text.size();i++){
            if(text[i] == ' '){
                mb[s.size()].push_back(s);
                s = "";
            }
            else{
                if(text[i]>='A' and text[i]<='Z'){
                    s+=((text[i]-'A')+'a');
                }
                else{
                    s+=text[i];
                }
            }
        }
        mb[s.size()].push_back(s);
        string ans = "";
        int flag = 0;
        for(auto &it:mb){
            for(auto &i:it.second){
                if(!flag){
                    flag= 1;
                    char d = (i[0]-'a')+'A';
                    string sd="";
                    sd+=d;
                    sd+=i.substr(1,i.size()-1);
                    ans+=sd;
                    ans+=' ';
                }
                else{
                    ans+=i;
                    ans+=' ';
                }
            }
        }
        ans.pop_back();
        return ans;
    }
};