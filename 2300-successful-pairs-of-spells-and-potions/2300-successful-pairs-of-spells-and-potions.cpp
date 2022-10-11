class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<long long> vb(potions.size());
        for(int i =0;i<potions.size();i++){
            vb[i] = (long long)potions[i];
        }
        sort(vb.begin(),vb.end());
        long long d;
        vector<int> ans;
        for(int i = 0;i<spells.size();i++){
            d = ceil((long double)success/spells[i]);
            cout<<d<<endl;
            auto it = (vb.size()-(lower_bound(vb.begin(),vb.end(),d)-vb.begin()));
            // if(it>0){
            //     it--;
            // }
            ans.push_back(it);
        }
        return ans;
    }
};