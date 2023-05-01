class Solution {
public:
    double average(vector<int>& salary) {
        long double sum = accumulate(salary.begin(),salary.end(),0ll);
        sum-=*max_element(salary.begin(),salary.end());
        sum-=*min_element(salary.begin(),salary.end());
        cout<<setprecision(5)<<fixed;
        return (double)(sum/(salary.size()-2));
    }
};