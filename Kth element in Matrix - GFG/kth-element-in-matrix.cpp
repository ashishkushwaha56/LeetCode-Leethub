//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  priority_queue<int> q;
  vector<int> v;
  for(int i = 0;i<n;i++){
  	for(int j = 0;j<n;j++){
  		v.push_back(mat[i][j]);
  	}
  }
//   for(auto &it:v){
//       cout<<it<<" ";
//   }
//   cout<<endl;
  int i = 0;
  for(i = 0;i<k;i++){
  	q.push(v[i]);
  }
  for(i = k;i<v.size();i++){
    //   cout<<q.top()<<endl;
  	if(q.top()>v[i]){
  	    
  		q.pop();
  		q.push(v[i]);
  	}
  }
  return q.top();
  // while(i<k){
  // 	for(;j<n;j++){
  // 		if(!ok){
  // 			break;
  // 		}
  // 		for(d = 0;d<n;d++){
  // 			if(i>=k){
  // 				ok = false;
  // 				break;
  // 			}
  // 			q.push(mat[j][d]);
  // 			i++;
  // 		}
  // 	}
  // 	if(i>=k) break;
  // }
  // for(;)

}