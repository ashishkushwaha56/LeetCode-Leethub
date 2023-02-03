class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mb;
        for(int i = 0;i<arr.size();i++){
            mb[arr[i]]++;
        }
        vector<pair<int,int>> v(mb.begin(),mb.end());
        sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
           return a.second<b.second; 
        });
        int i=0;
        int cnt;
        while(i<v.size()){
            cnt=min(v[i].second,k);
            k-=cnt;
            if(v[i].second-cnt == 0)
                i++;
            if(k == 0) break;
            
        }
        return (v.size()-i);
    }
};