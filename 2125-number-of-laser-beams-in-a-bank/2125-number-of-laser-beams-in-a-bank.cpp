class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int i = 0;
        int prev;
        while(i<bank.size() and count(bank[i].begin(),bank[i].end(),'1') == 0){
            i++;
        }
        if(i<bank.size()){
            prev = count(bank[i].begin(),bank[i].end(),'1');
        }
        int ans = 0;
        int curr;
        while(i<bank.size()){
                i++;
                while(i<bank.size() and count(bank[i].begin(),bank[i].end(),'1') == 0){
                    i++;
                }
                if(i == bank.size()){
                    break;
                }
                curr = count(bank[i].begin(),bank[i].end(),'1');
                ans+=(prev*curr);
                prev = curr;
        }
        return ans;
    }
};