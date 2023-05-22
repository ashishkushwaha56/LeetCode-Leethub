class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> v;
        string a;
        for(int i = 1;i<n+1;i++){
            a = to_string(i);
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(int i = 0;i<v.size();i++){
            ans.push_back(stoi(v[i]));
        }
        return ans;
    }
};