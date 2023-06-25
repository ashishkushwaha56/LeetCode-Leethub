class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
		int a;
		while(n>0){
		    a=n%26;
		    if(a == 0){
		        s+='Z';
		        n--;
		    }
		    else{
		        s+=((a-1)+'A');
		    }
		    n/=26;
		}
		reverse(s.begin(),s.end());
		return s;
    }
};