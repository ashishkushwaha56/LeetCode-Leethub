class Solution {
public:
    vector<int> closestDivisors(int num) {
        int s1 = num+1;
        int s2 = num+2;
        int ans = num+2;
        int l1 = 1;
        int l2 = num+2;
        for(int i = 1;i*i<=s1;i++){
            if(s1%i == 0){
                // cout<<i<<" "<<s1/i<<endl;
                if(ans>max(i,s1/i)-min(i,s1/i)){
                    l1=min(i,s1/i);
                    l2 = max(i,s1/i);
                    ans = max(i,s1/i)-min(i,s1/i);
                }
            }
        }
        for(int i = 1;i*i<=s2;i++){
            if(s2%i == 0){
                if(ans>max(i,s2/i)-min(i,s2/i)){
                    l1=min(i,s2/i);
                    l2 = max(i,s2/i);
                    ans = max(i,s2/i)-min(i,s2/i);
                }
            }
        }
        return {l1,l2};
    }
};