//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string a, string b) {
        int n=a.size(),m=b.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int maxi=0;
        for (int i=1;i<=n;i++) 
            for (int j=1;j<=m;j++) {
                // dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if (a[i-1]==b[j-1]) dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
                maxi=max(maxi,dp[i][j]);
            }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends