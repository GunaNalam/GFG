//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int call(vector<vector<int>> &matrix, int m, int n, int x) {
        int cnt = 0;
        for (int i = 0; i < m; i++) 
            cnt += upper_bound(matrix[i].begin(),matrix[i].end(),x)-matrix[i].begin();
        return cnt;
    }
    int median(vector<vector<int>> &matrix, int n, int m){
        int s=matrix[0][0],e=matrix[0][m-1];
        // s-mini,e-maxi
        for (auto i:matrix) {
            s=min(s,i[0]);
            e=max(e,i[m-1]);
        }
        int left=(n*m)/2;
        while (s<=e) {
            int mid=s+(e-s)/2;
            int c=call(matrix,n,m,mid);
            if (c<=left) s=mid+1;
            else e=mid-1;
        }
        return s;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends