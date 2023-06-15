class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        stack<int> sd;
        for(int i = 0;i<v.size();i++){
            if(sd.empty()){
                sd.push(v[i]);
            }
            else{
                while(!sd.empty() and sd.top()>0 and v[i]<0 and abs(v[i])>sd.top())
                    sd.pop();
                if(!sd.empty() and sd.top()>0 and v[i]<0 and abs(v[i])==sd.top()){
                    sd.pop();
                    continue;
                }
                else if(!sd.empty() and sd.top()>0 and v[i]<0 and abs(v[i])<sd.top()){
                    continue;
                }
                else{
                    sd.push(v[i]);
                }
            }
        }
        vector<int>ans;
        while(!sd.empty()){
            ans.push_back(sd.top());
            sd.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};