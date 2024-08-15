//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int count(string s,int start,int end,bool isTrue) {
        if (start>end) return 0;
        if (start==end) return (isTrue?(s[start]=='T'):(s[start]=='F'));
        int count1=0;
        for (int k=start+1;k<end;k+=2) {
            int TrueLeft=count(s,start,k-1,1);
            int TrueRight=count(s,k+1,end,1);
            int FalseLeft=count(s,start,k-1,0);
            int FalseRight=count(s,k+1,end,0);
            if (s[k]=='&') {
                if (isTrue) count1+=TrueLeft*TrueRight;
                else count1+=FalseLeft*FalseRight+TrueLeft*FalseRight+TrueRight*FalseLeft;
            }
            if (s[k]=='|') {
                if (isTrue) count1+=TrueLeft*TrueRight+TrueLeft*FalseRight+TrueRight*FalseLeft;
                else count1+=FalseLeft*FalseRight;
            }
            if (s[k]=='^') {
                if (isTrue) count1+=TrueLeft*FalseRight+TrueRight*FalseLeft;
                else count1+=TrueLeft*TrueRight+FalseRight*FalseLeft;
            }
        }
        return count1;
    }
    int countWays(int n, string s){
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,0)));
        for (int start=n-1;start>=0;start--) {
            dp[start][start][0]=(s[start]=='F');
            dp[start][start][1]=(s[start]=='T');
            for (int end=start+1;end<n;end++) {
                for (int k=start+1;k<end;k+=2) {
                    int TrueLeft=dp[start][k-1][1];
                    int TrueRight=dp[k+1][end][1];
                    int FalseLeft=dp[start][k-1][0];
                    int FalseRight=dp[k+1][end][0];
                    int MOD=1e3+3;
                    if (s[k]=='&') {
                        dp[start][end][1]=(dp[start][end][1]+TrueLeft*TrueRight)%MOD;
                        dp[start][end][0]=(dp[start][end][0]+FalseLeft*FalseRight+TrueLeft*FalseRight+TrueRight*FalseLeft)%MOD;
                    }
                    if (s[k]=='|') {
                        dp[start][end][1]=(dp[start][end][1]+TrueLeft*TrueRight+TrueLeft*FalseRight+TrueRight*FalseLeft)%MOD;
                        dp[start][end][0]=(dp[start][end][0]+FalseLeft*FalseRight)%MOD;
                    }
                    if (s[k]=='^') {
                        dp[start][end][1]=(dp[start][end][1]+TrueLeft*FalseRight+TrueRight*FalseLeft)%MOD;
                        dp[start][end][0]=(dp[start][end][0]+TrueLeft*TrueRight+FalseRight*FalseLeft)%MOD;
                    }
                }
            }
        }
        return dp[0][n-1][1]%1003;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends