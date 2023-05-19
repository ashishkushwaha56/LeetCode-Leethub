class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string sea) {
        vector<vector<string>> ans;
        vector<string> v;
        string s = "";
        int k;
        for(int i = 0;i<sea.size();i++){
            s+=sea[i];
            // k = 0;
            for(int j=0;j<products.size();j++){
                k = 0;
                while(k<min(products[j].size(),s.size())){
                    if(s[k]!=products[j][k]){
                        break;
                    }
                    k++;
                }
                if(k==s.size()){
                    v.push_back(products[j]);
                }
            }
            sort(v.begin(),v.end());
            while(v.size()>3){
                v.pop_back();
            }
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};