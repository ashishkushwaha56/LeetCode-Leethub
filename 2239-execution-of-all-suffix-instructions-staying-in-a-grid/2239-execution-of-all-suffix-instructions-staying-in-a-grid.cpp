class Solution {
public:
        vector<int> ans;

    unordered_map<char,pair<int,int>> mb = {
        {'D',{1,0}},{'U',{-1,0}},{'L',{0,-1}},{'R',{0,1}}
    };
    void check(int &n,pair<int,int>&p,string &s,int i,int j){

        if(p.first+mb[s[i]].first<0 or p.second+mb[s[i]].second<0 or p.first+mb[s[i]].first==n or p.second+mb[s[i]].second==n or i == s.size()){
            ans.push_back(i-j);
            return;
        }
        p.first+=mb[s[i]].first;
        p.second+=mb[s[i]].second;
        check(n,p,s,i+1,j);
        p.first-=mb[s[i]].first;
        p.second-=mb[s[i]].second;
        
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        pair<int,int>p = make_pair(startPos[0],startPos[1]);
        for(int i = 0;i<s.size();i++){
            check(n,p,s,i,i);
        }
        return ans;
    }
};