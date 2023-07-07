class Solution {
public:
    int countVowelSubstrings(string word) {
        set<char> sd = {'a','e','i','o','u'};
        int ans = 0;
        for(int i = 0;i<word.size();i++){
            set<char>d;
            // cout<<"i = "<<i<<endl;
            for(int j = i;j<word.size();j++){
                if(sd.find(word[j])!=sd.end()){
                    d.insert(word[j]);
                    if(d.size() == 5) {
                        // cout<<j<<endl;
                        ans++;
                    }
                }
                else break;
                
            }
            // cout<<"ans = "<<ans<<endl;
        }
        return ans;
    }
};