class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string ans = "";
        set<int> st;
        vector<pair<string,pair<int,int>>> v;
        bool ok;
        int j,k;
        vector<bool> bt(s.size(),true);
        for(int i = 0;i<indices.size();i++){
            st.insert(indices[i]);
            ok = true;
            j = indices[i];
            k = 0;
            while(k<sources[i].size() and j<s.size()){
                if(sources[i][k]!=s[j]){
                    ok = false;
                    break;
                }
                k++;j++;
            }
            if(!ok){
                st.erase(indices[i]);
            }
            else if(k<sources[i].size()){
                st.erase(indices[i]);
            }
            else{
                int t = indices[i];
                while(t<j){
                    bt[t] = false;
                    t++;
                }
                v.push_back({targets[i],{indices[i],t}});
            }
        }
        sort(v.begin(),v.end(),[&](pair<string,pair<int,int>>&a,pair<string,pair<int,int>>&b){
           return a.second.first<b.second.first; 
        });
        j = 0;
        for(int i = 0;i<s.size();){
            if(st.find(i)!=st.end()){
                ans+=v[j].first;
                i = v[j].second.second;
                j++;
            }
            else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};