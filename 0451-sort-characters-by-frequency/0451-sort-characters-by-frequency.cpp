class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,int>> vb(26);
        vector<int> vc(10);
        for(int i = 0;i<s.size();i++){
            if(s[i]>='a' and s[i]<='z')
                vb[s[i]-'a'].first++;
            else if(s[i]>='A' and s[i]<='Z')
                vb[s[i]-'A'].second++;
            else{
                vc[s[i]-'0']++;
            }
        }
        vector<pair<char,int>> res;
        for(int i = 0;i<26;i++){
            res.push_back({i+'a',vb[i].first});
            res.push_back({i+'A',vb[i].second});
        }
        for(int i = 0;i<10;i++){
            res.push_back({i+'0',vc[i]});
        }
        sort(res.begin(),res.end(),[&](pair<char,int>&a,pair<char,int>&b){           
            return a.second>b.second;
        });
        string ans ="";
        int c;
        char d;
        for(auto &it:res){
            c = it.second;
            d = it.first;
            while(c--){
                ans+=d;
            }
        }
        return ans;
    }
};