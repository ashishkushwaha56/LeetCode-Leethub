class MyCalendarThree {
public:
    map<int,int> mb;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mb[start]++;
        mb[end]--;
        int s = 0, ans = 0;
        for(auto &it:mb){
            s+=it.second;
            ans= max(ans,s);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */