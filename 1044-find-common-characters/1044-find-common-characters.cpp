class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> v(26);
        for(auto &it:words[0]){
            v[it-'a']++;
        }
        vector<int> b(26);
        for(int i = 1;i<words.size();i++){
            for(int j = 0;j<words[i].size();j++){
                b[words[i][j]-'a']++;
            }
            for(int j = 0;j<26;j++){
                v[j]=min(b[j],v[j]);
                b[j] =0;
            }
        }
        vector<string> sd;
        string d = "";
        for(int i = 0;i<26;i++){
            d+=(i+'a');
            while(v[i]>0){
                sd.push_back(d);
                v[i]--;
            }
            d = "";
        }
        return sd;
    }
};