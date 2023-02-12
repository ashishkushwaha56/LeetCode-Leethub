class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        string a,b;
        deque<int> q;
        for(auto &it:nums){
            q.push_front(it);
        }
        while(!q.empty()){
            if(q.size()>=2){
                a = to_string(q.front());
                b = to_string(q.back());
                // cout<<a<<" "<<b<<endl;
                ans+=stol((b+a));
                q.pop_front();
                q.pop_back();
            }
            else{
                ans+=q.front();
                q.pop_front();
            }
        }
        return ans;
    }
};