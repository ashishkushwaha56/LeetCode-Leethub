class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> s;
        for(auto &it:dictionary){
            s.insert(it);
        }
        string ans ="";
        vector<string> v;
        string b = "";
        for(int i = 0;i<sentence.size();i++){
            if(sentence[i] == ' '){
                v.push_back(b);
                b = "";
            }
            else{
                b+=sentence[i];
            }
        }
        v.push_back(b);
        int j = 0;
        b = "";
        for(int i=0;i<v.size();i++){
            j = 0;
            b = "";
            for(j = 0;j<v[i].size();j++){
                b+=v[i][j];
                if(s.find(b)!=s.end()){
                    v[i]=b;
                    break;
                }
            }
        }
        for(auto &it:v){
            ans+=it;
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};