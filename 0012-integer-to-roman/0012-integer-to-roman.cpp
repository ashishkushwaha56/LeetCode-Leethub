class Solution {
public:
    string intToRoman(int num) {
        vector<string> ans;
        int i = 0;
        while(num){
            string s = "";
            if(i == 0){
                if(num%10 ==  1){
                    ans.push_back("I");
                }
                else if(num%10 ==  5)
                    ans.push_back("V");
                else if(num%10 >5 and num%10 <9){
                    s+='V';
                    for(int j = 0;j<num%10-5;j++)
                        s+='I';
                    ans.push_back(s);
                }
                else if(num%10 >1 and num%10 <4)
                {
                    // s+='V';
                    for(int j = 0;j<num%10;j++)
                        s+='I';
                    ans.push_back(s);
                }
                else if(num%10  == 4){
                    ans.push_back("IV");
                }
                else if(num%10  == 9){
                    ans.push_back("IX");
                }
            }
            else if(i == 1){
                if(num%10 ==  1){
                    ans.push_back("X");
                }
                else if(num%10 ==  5)
                    ans.push_back("L");
                else if(num%10 >5 and num%10 <9){
                    s+='L';
                    for(int j = 0;j<num%10-5;j++)
                        s+='X';
                    ans.push_back(s);
                }
                else if(num%10 >1 and num%10 <4)
                {
                    // s+='V';
                    for(int j = 0;j<num%10;j++)
                        s+='X';
                    ans.push_back(s);
                }
                else if(num%10  == 4){
                    ans.push_back("XL");
                }
                else if(num%10  == 9){
                    ans.push_back("XC");
                }
            }
            else if(i == 2){
                if(num%10 ==  1){
                    ans.push_back("C");
                }
                else if(num%10 ==  5)
                    ans.push_back("D");
                else if(num%10 >5 and num%10 <9){
                    s+='D';
                    for(int j = 0;j<num%10-5;j++)
                        s+='C';
                    ans.push_back(s);
                }
                else if(num%10 >1 and num%10 <4)
                {
                    // s+='V';
                    for(int j = 0;j<num%10;j++)
                        s+='C';
                    ans.push_back(s);
                }
                else if(num%10  == 4){
                    ans.push_back("CD");
                }
                else if(num%10  == 9){
                    ans.push_back("CM");
                }
            }
            else if(i ==3){
                for(int j = 0;j<num%10;j++)
                    s+='M';
                ans.push_back(s);
            }
            i++;
            num/=10;
        }
        string res = "";
        for(int i = ans.size()-1;i>=0;i--){
            res+=ans[i];
        }
        return res;
    }
};