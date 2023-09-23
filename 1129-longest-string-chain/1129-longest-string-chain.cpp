class Solution {
public:
    int longestStrChain(vector<string>& words) {
        map<string,int> mb;
        set<string> sd(words.begin(),words.end());
        function<int(string)> helper = [&](string a)->int{
            if(sd.find(a)==sd.end()) return 0;
            if(mb.find(a)!=mb.end()) return mb[a];
            int ans = 0;
            for(int i = 0;i<a.size();i++){
                string temp = a.substr(0,i)+a.substr(i+1,a.size()-i);
                ans = max(ans,1+helper(temp));
            }
            return mb[a] = ans;
        };
        sort(words.begin(),words.end(),[&](string &a,string &b){
            return a.size()<b.size();
        });
        int ans = 0;
        for(auto &it:words){
            ans = max(ans,helper(it));
        }
        return ans;
    }
};