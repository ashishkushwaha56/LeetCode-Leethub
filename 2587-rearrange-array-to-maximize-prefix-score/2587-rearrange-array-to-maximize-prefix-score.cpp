class Solution {
public:
    int maxScore(vector<int>& nums) {
        priority_queue<int> v1;
        priority_queue<int,vector<int>,greater<int>> v2;
        int d = 0;
        
        
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                d++;
                continue;
            }
            if(nums[i]<0){
                v1.push(nums[i]);
            }
            else{
                v2.push(nums[i]);
            }
        }
//         r = v1;
//         s = v2;
//         while(!r.empty()){
//             cout<<r.top()<<" ";
//             r.pop();
//         }
//         cout<<endl;
        
//         while(!s.empty()){
//             cout<<s.top()<<" ";
//             s.pop();
//         }
//         cout<<endl;
        int cnt = 0;
        int ans = 0;
        while(!v1.empty() or !v2.empty()){
            if(!v1.empty()){
                if(ans+v1.top()<=0){
                    if(!v2.empty()){
                        ans+=v2.top();
                        v2.pop();
                        cnt++;
                    }
                    else{
                        break;
                    }
                }
                else{
                    ans+=v1.top();
                    v1.pop();
                    cnt++;
                }
            }
            else{
                ans+=v2.top();
                v2.pop();
                cnt++;
            }
        }
        if(cnt!=0){
            cnt+=d;
        }
        return cnt;
        
    }
};