class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        vector<int> v(26);
        vector<string> s={"qwertyuiop",
        "asdfghjkl",
        "zxcvbnm"};
        for(int i = 0;i<3;i++){
            for(int j = 0;j<s[i].size();j++){
                v[s[i][j]-'a'] = i;
            }
        }
        int last;
        for(int i =0;i<words.size();i++){
            int j = 0;
            cout<<words[i]<<endl;
            last = -1;
            while(j<words[i].size()){
                if(last!=-1){
                    if(words[i][j]>='A' and words[i][j]<='Z'){
                        if(last!=v[words[i][j]-'A']) break;
                    }
                    else{
                        if(last!=v[words[i][j]-'a']) break;
                    }
                    
                }
                else{
                    if(words[i][j]>='A' and words[i][j]<='Z'){
                        last=v[words[i][j]-'A'];
                    }
                    else{
                        last=v[words[i][j]-'a'];
                    }
                }
                j++;
            }
            if(j==words[i].size()){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};