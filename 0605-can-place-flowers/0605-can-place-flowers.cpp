class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int a;
        int k = 0;
        bool ok = false;
        for(int i = 0;i<flowerbed.size();i++){
            if(n ==0) return true;
            if(flowerbed[i] == 1){
                ok = true;
                if(!(cnt&1)){
                    if(k ==0){
                        a = (cnt/2);
                        k++;
                    }
                    else{
                        a=(cnt/2)-1;
                    }
                }
                else{
                    a = (cnt/2);
                }
                n-=min(n,a);
                cnt = 0;
            }
            else{
                cnt++;
            }
        }
        if(!ok){
            if(cnt&1)
            a = cnt/2+1;
            else
                a= cnt/2;
        }
        else{
             a = cnt/2;
        }
       
        n-=min(n,a);
        return n==0;
        
    }
};