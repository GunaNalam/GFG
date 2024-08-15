//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n,1),store(n);
        for (int i=0;i<n;i++) store[i]=i;
        for (int i=1;i<n;i++) {
            for (int j=0;j<i;j++) {
                if (arr[i]>arr[j] && 1+dp[j]>dp[i]) {
                    dp[i]=1+dp[j];
                    store[i]=j;
                }
            }
        }
        int index=0;
        for (int i=1;i<n;i++) if (dp[i]>dp[index]) index=i;
        vector<int> res;
        while (index!=store[index]) {
            res.push_back(arr[index]);
            index=store[index];
        }
        res.push_back(arr[index]);
        reverse(res.begin(),res.end());
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends