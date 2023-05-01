class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int sum1 = 0,sum2 = 0;
        for(int i = 0;i<player1.size();i++){
            if(i>1){
                if(player1[i-1]==10 or player1[i-2] == 10){
                    sum1+=(2*player1[i]);
                }
                else{
                    sum1+=player1[i];
                }
                if(player2[i-1]==10 or player2[i-2] == 10){
                    sum2+=(2*player2[i]);
                }
                else{
                    sum2+=player2[i];
                }
                
            }
            else if(i>0){
                if(player1[i-1]==10){
                    sum1+=(2*player1[i]);
                }
                else{
                    sum1+=player1[i];
                }
                if(player2[i-1]==10){
                    sum2+=(2*player2[i]);
                }
                else{
                    sum2+=player2[i];
                }
            }
            
            else{
                sum1+=player1[i];
                sum2+=player2[i];
            }
        }
        if(sum1>sum2) return 1;
        else if(sum1<sum2) return 2;
        return 0;
    }
};