//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    set<vector<int>> ans;
	void check(vector<int> &v, vector<int>&temp, int &i) {
		if (i >= v.size()) {
			ans.insert(temp);
			return;
		}
		temp.push_back(v[i]);
		i++;
		check(v, temp, i);

		temp.pop_back();
		check(v, temp, i);
		i--;
	}
	vector<vector<int> > AllSubsets(vector<int> arr, int n)
	{
		vector<int>temp;
		int i = 0;
		sort(arr.begin(), arr.end());
		check(arr, temp, i);

		vector<vector<int>> res;
		auto it = ans.begin();
		for (it = ans.begin(); it != ans.end(); ++it) {
			res.push_back(*(it));
		}
		sort(res.begin(), res.end());
		return res;
	}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends