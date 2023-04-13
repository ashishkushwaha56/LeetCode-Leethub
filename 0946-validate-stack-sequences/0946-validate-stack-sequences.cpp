class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        set<int> s;
        stack<int> ans;
        int i = 0;
        int j = 0;
        int n = pushed.size();
        while(j<n){
            if(ans.empty()){
                ans.push(pushed[i]);
                s.insert(pushed[i]);
                i++;
            }
            else{
                if(s.find(popped[j])==s.end()){
                    if(i>=n) {break;}
                    else {
                    ans.push(pushed[i]);
                    s.insert(pushed[i]);
                    i++;
                    }
                }
                else if(s.find(popped[j])!=s.end()){
                    if(ans.top() == popped[j]){
                        ans.pop();
                        s.erase(popped[j]);
                        j++;
                    }
                    else if(i>=n) {
                        break;
                    }
                    else{
                        s.insert(pushed[i]);
                        ans.push(pushed[i]);
                        i++;
                    }
                }
            }
        }
        return ans.empty();
    }
};