class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a = 0,b = 0;
        // sort(bills.begin(),bills.end());
        for(auto &it:bills){
            if(it == 20){
                if(a>=1 and b>=1){
                    a--;b--;

                }
                else if(a>=3){
                    a-=3;
                }
                else  return false;
            }
            else if(it == 10){
                if(a>=1){ a--;b++;}
                else return false;
            }
            else a++;
        }
        return true;
    }
};