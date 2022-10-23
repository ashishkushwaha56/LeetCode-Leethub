class Solution {
public:
    int nextBeautifulNumber(int n) {
        string s = to_string(n);
        int ans = INT_MAX;
        vector<int> v={1,22,122,333,1333,4444,14444,22333,55555,122333,155555,224444,666666,1224444};
        
        for(auto &it:v){
            string a = to_string(it);
            if(a.size()<s.size()){
                continue;
            }
            if(a.size()>s.size()){
                ans = min(ans,it);
            }
            else{
                do{
                    if(a>s){
                        ans = min(ans,stoi(a));
                    }
                }while(next_permutation(a.begin(),a.end()));
            }
        }
        return ans;
    }
};