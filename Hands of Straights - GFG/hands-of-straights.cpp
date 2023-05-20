//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int g, vector<int> &hand) {
        if(N%g!=0) return false;
        map<int,int> mb;
        int last = -1;
        int k = 0;
        int d;
        for(auto &it:hand){
            mb[it]++;
        }
        while(!mb.empty()){
            auto it = mb.begin();
            d = (*it).first;
            k = 0;
            last = d;
            it++;
            // (*it).second--;
            mb[d]--;
            k++;
            if(mb[d] == 0) mb.erase(d);
            while(it!=mb.end() and k<g){
                if((*it).first == last+1){
                    d = (*it).first;
                    last = d;
                    it++;
                    mb[d]--;
                    k++;
                    if(mb[d] == 0) mb.erase(d);
                }
                else{
                    return false;
                }
            }
            if(k!=g){
                return false;
            }
        }
        return true;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends