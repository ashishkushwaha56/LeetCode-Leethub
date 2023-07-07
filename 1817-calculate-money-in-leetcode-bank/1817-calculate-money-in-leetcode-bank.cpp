class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int i = 1;
        int j = i;
        int k = 1;
        while(k<=n){
            ans+=(j);
            cout<<j<<endl;
            if(k%7 == 0){
                i++;
                j = i;
            }
            else{
                j++;
            }
            k++;
        }
        return ans;
    }
};