class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int ans = 0;
        queue<int>q;
        vector<int>vis(1001);
        int temp;
        q.push(start);
        int t =1;
        int c = 0;
        if(start == goal) return 0;
        int ss;
        while(!q.empty()){
            ss = q.size();
            while(ss--){
                temp = q.front();
                q.pop();
            // t--;
            // cout<<temp<<" ";
                if(temp == goal) return (ans);
                if(temp<0 or temp>1000 or vis[temp]){
                    continue;
                }
                vis[temp] = 1;
                for(int i = 0;i<nums.size();i++){
                    q.push(temp+nums[i]);
                    q.push(temp-nums[i]);
                    q.push((temp^nums[i]));
                // c+=3;
                }
            }
            ans++;
        }
        return -1;
    }
};