class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int res = 0;
        int l = -1;
        int r = -1;
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                l = i;
                r = j;
                res = 0;
                auto it = lower_bound(arr.begin()+r+1,arr.end(),arr[l]+arr[r]);
                if(it == arr.end()) continue;
                if(*it!=arr[l]+arr[r]) continue;
                res=3;
                l = r;
                r = it-arr.begin();
                while(true){
                    auto it1 = lower_bound(arr.begin()+r+1,arr.end(),arr[l]+arr[r]);
                    if(it1 == arr.end()){
                        break;
                    }
                    if(*it1!=arr[l]+arr[r]){
                        break;
                    }
                    res++;
                     l = r;
                    r = it1-arr.begin();
                }
                ans = max(ans,res);
            }
        }
        return ans;
    }
};