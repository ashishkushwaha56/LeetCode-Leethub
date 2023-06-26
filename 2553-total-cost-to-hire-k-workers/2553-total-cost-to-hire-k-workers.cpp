class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cc) {
        map<int,set<int>> mb;
        int l = 0;
        int r = costs.size()-1;
        long long ans =0;
        if(2*cc>=costs.size()){
            for(int i = 0;i<costs.size();i++){
                mb[costs[i]].insert(i);
            }
            while(k>0){
                auto it = mb.begin();
                ans+=(*it).first;
                auto it1 = (*it).second.begin();
                mb[(*it).first].erase(*it1);
                if(mb[(*it).first].size()==0) mb.erase((*it).first);
                k--;
            }
            
        }
        else{
            while(cc>0){
                mb[costs[l]].insert(l);
                l++;
                mb[costs[r]].insert(r);
                r--;
                cc--;
            }
            while(l<=r and k>0){
                auto it = mb.begin();
                ans+=(*it).first;
                auto it1 = (*it).second.begin();
                if(*it1<l){
                    mb[costs[l]].insert(l);
                    l++;
                }
                else{
                    mb[costs[r]].insert(r);
                    r--;
                }
                mb[(*it).first].erase(*it1);
                if(mb[(*it).first].size()==0) mb.erase((*it).first);
                k--;
            }
            while(k>0){
                auto it = mb.begin();
                ans+=(*it).first;
                auto it1 = (*it).second.begin();
                mb[(*it).first].erase(*it1);
                if(mb[(*it).first].size()==0) mb.erase((*it).first);
                k--;
            }
        }
        return ans;
    }
};