class Solution {
public:
    void lps_(vector<int>&lps,string b,int m){
        int j = 0,i = 1;
        while(i<m){
            if(b[i] == b[j]){
                j++;
                lps[i] = j;
                i++;
            }
            else{
                if(j!=0) j = lps[j-1];
                else {lps[i] = 0;i++;}
            }
        }
    }
    bool kmp(string a,string b,vector<int>&lps,int n,int m){
        int i = 0,j = 0;
        while(i<n and j<m){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                if(j!=0) j = lps[j-1];
                else i++;
            }
            if(j==m) break;
        }
        return (j==m);
    }
    int repeatedStringMatch(string a, string b) {
        if(a==b) return 1;
        int n = a.size();
        int m=b.size();
        int ans = 1;
        string d = a;
        int j = n;
        while(j<m){
            a+=d;
            j+=n;
            ans++;
        }
        vector<int>lps(m,0);
        lps_(lps,b,m);
        if(kmp(a,b,lps,j,m)) return ans;
        else if(kmp(a+d,b,lps,j+n,m)) return ans+1;
        return -1; 
    }
};