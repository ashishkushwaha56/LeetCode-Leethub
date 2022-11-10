class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        map<long double,pair<int,int>> mb;
        for(int i = 0;i<arr.size()-1;i++){
            for(int j = i+1;j<arr.size();j++){
                mb[((long double)arr[i]/arr[j])] = {arr[i],arr[j]};
            }
        }
        vector<pair<long double,pair<int,int>>> v;
        for(auto &it:mb){
            v.push_back(it);
        }
        sort(v.begin(),v.end(),[&](pair<long double,pair<int,int>> &a,pair<long double,pair<int,int>> &b){
            return a.first<b.first;
        });
        return {v[k-1].second.first,v[k-1].second.second};
    }
};