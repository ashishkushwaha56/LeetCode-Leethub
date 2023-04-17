class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<pair<int,int>> ans;
        vector<pair<int,int>> v;
        pair<int,int> p;
        for(int i = 0;i<arr.size();i++){
            p = {min(arr[i],i),max(arr[i],i)};
            v.push_back(p);
        }
        sort(v.begin(),v.end());
        for(int i = 0;i<v.size();i++){
            if(ans.empty()){
                ans.push(v[i]);
            }
            else{
                if(ans.top().second>=v[i].first){
                    p = {ans.top().first,max(v[i].second,ans.top().second)};
                    ans.pop();
                    ans.push(p);
                }
                else{
                    ans.push(v[i]);
                }
            }
        }
        return ans.size();
    }
};