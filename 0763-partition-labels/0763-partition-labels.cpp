class Solution {
public:
    vector<int> partitionLabels(string s) {
       stack<pair<int,int>> sb;
        pair<int,int> p;
        pair<int,int> a;
        for(int i= 0;i<s.size();i++){
            p.first = i;
            for(int j = s.size()-1;j>=i;j--){
                if(s[j] == s[i]){
                    p.second = j;
                    break;
                }
            }
            if(sb.empty()){
                sb.push(p);
                continue;
            }
            if(p.first<=sb.top().second){
                a = sb.top();
                sb.pop();
                p.first = min(a.first,p.first);
                p.second = max(a.second,p.second);
                sb.push(p);
            }
            else{
                sb.push(p);
            }
        }
        vector<int> ans;
        while(!sb.empty()){
            ans.push_back(sb.top().second-sb.top().first+1);
            sb.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};