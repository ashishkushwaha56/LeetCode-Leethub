class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> v(sqrt(right)+1,true);
        vector<int> primes;
        v[0] = v[1] = false;
        for(int i = 2;i*i<=right;i++){
            if(v[i]){ 
                primes.push_back(i);
                // cout<<i<<" ";
                for(int j = i*i;j<=sqrt(right);j+=i){
                    v[j] = false;
                }
            }
        }
        // cout<<endl;
        // for(auto &it: primes){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        if(left<2 and right>=2){
            left = 2;
        }
        vector<int> ans;
        vector<bool> block(right-left+1,true);
        for(auto &i:primes){
            int lower = (left/i);
            if(lower<=1){
                lower = i+i;
            }
            else if(left%i){
                lower = (lower*i)+i;
            }
            else {
                lower = (lower*i);
            }
            
            for(int j = lower;j<=right;j+=i){
                block[j-left] = false;
            }
            // for(int k = 0;k<block.size();k++){
            //     cout<<block[k]<<" ";
            // }
            // cout<<endl;
            
        }
        for(int it = left;it<=right;it++){
                if(block[it-left]){ ans.push_back(it);}
            }
        // for(auto &ot:ans){
        //     cout<<ot<<" ";
        // }
        // cout<<endl;
        int a,b;
        if(ans.size()<2) return {-1,-1};
        int mine = ans[ans.size()-1]-ans[ans.size()-2];
        a = ans[ans.size()-2],b = ans[ans.size()-1];
        for(int i = ans.size()-1;i>0;i--){
            if(ans[i]-ans[i-1]<=mine){
                mine=ans[i]-ans[i-1];
                a = ans[i-1];
                b = ans[i];
            }
        }
        return {a,b};
    }
};