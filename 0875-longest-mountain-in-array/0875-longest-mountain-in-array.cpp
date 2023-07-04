class Solution {
public:
    int longestMountain(vector<int>& arr) {
        vector<int> v;
        for(int i = 1;i<arr.size()-1;i++){
            if(arr[i]>arr[i-1] and arr[i]>arr[i+1]){
                v.push_back(i);
            }
        }
        int ans = 0;
        int cnt = 0;
        for(auto &it:v){
            cnt = 0;
            for(int j = it;j>0;j--){
                if(arr[j]>arr[j-1]){
                    cnt++;
                }
                else break;
            }
            for(int j = it;j<arr.size()-1;j++){
                if(arr[j]>arr[j+1]){
                    cnt++;
                }
                else break;
            }
            ans = max(ans,cnt+1);
        }
        return ans;
    }
};