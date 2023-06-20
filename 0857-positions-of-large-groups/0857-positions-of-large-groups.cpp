class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int cnt = 1;
        int l = 0;
        vector<vector<int>> v;
        for(int i = 1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                if(cnt>=3){
                    v.push_back({l,i-1});
                }
                cnt = 1;
                l = i;
            }
            else cnt++;
        }
        if(cnt>=3){
            v.push_back({l,(int)s.size()-1});
        }
        sort(v.begin(),v.end());
        return v;
    }
};