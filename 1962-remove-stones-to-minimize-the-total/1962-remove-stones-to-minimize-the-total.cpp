class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> p;
        for(int i = 0;i<piles.size();i++){
            p.push(piles[i]);
        }
        
        int temp;
        while(k--){
            temp = p.top();
            p.pop();
            if(temp == 0){
                break;
            }
            if(temp&1){
                p.push(temp/2+1);
            }
            else{
                p.push(temp/2);
            }
            
        }
        int ans = 0;
        while(!p.empty()){
            ans+=p.top();
            p.pop();
        }
        return ans;
    }
};