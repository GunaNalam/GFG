//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp(n,0);
        for (int i=1;i<n;i++) 
            for (int j=i-1;j>=0;j--) 
                if (nums[i]>nums[j]) dp[i]=max(dp[i],1+dp[j]);
        int maxi=0;
        for (int i=n-1;i>=0;i--) {
            int temp=0;
            for (int j=n-1;j>=i;j--) {
                if (nums[i]>nums[j]) temp=max(temp,1+dp[j]);
            } 
            if (temp && dp[i]) maxi=max(maxi,dp[i]+temp+1);
            dp[i]=temp;
        }
        // for (int i:dp) cout<<i<<" ";
        // cout<<"\n";
        return maxi;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
    }
}

// } Driver Code Ends