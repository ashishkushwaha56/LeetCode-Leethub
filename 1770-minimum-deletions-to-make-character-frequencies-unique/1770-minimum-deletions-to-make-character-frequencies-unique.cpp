class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26);
        for(int i = 0;i<s.size();i++){
            v[s[i]-'a']++;
        }
        map<int,int> mb;
        for(int i = 0;i<26;i++){
            if(v[i]>0)
                mb[v[i]]++;
        }
        auto it = mb.end();
        it--;
        int ans = 0;
        while(true){
            if((*it).second>1){
                // ans+=((*it).second-1);
                // // if(mb.find((*it).first-1)!=mb.end())
                // if(it!=mb.begin())
                //     mb[(*it).first-1] += (*it).second-1;
                int d = (*it).second;
                int e = (*it).first;
                if(d>e){
                    ans+=(d*e-(e*(e+1))/2);
                    for(int i = e-1;i>=1;i--){
                        mb[i]++;
                    }
                }
                else{
                    // cout<<e<<endl;
                    for(int i = e-1;i>=e-d+1;i--){
                        mb[i]++;
                        ans+=(e-i);
                    }
                }
            }
            if(it == mb.begin()) break;
            it--;
        }
        return ans;
    }
};