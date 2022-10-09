class Solution {
public:
    unordered_map<int,int> mb;
    int totalFruit(vector<int>& v) {
        int n = v.size();
        int l = 0;
        mb[v[l]] = 0;
        int ans = 1;
        for(int i =1;i<n;i++){
            if(mb.size() == 2 and mb.find(v[i])==mb.end()){
                auto it1 = mb.begin();
                auto it2 = mb.begin();
                it2++;
                if((*it1).second>(*it2).second){
                    l = (*it2).second+1;
                    mb.erase((*it2).first);
                }
                else{
                    l = (*it1).second+1;
                    mb.erase((*it1).first);
                }
            }
            mb[v[i]] = i;
            ans = max(ans,(i-l+1));
        }
        return ans;
    }
};