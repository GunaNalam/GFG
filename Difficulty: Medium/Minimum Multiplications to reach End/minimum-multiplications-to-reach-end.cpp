//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define pp pair<int,int> 
class Solution {
  public:
    int MOD=1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // if (start==end) return 0;
        vector<int> dist(1e5,1e5);
        priority_queue<pp,vector<pp>,greater<pp>> a;
        a.push({0,start});
        dist[start]=0;
        while (!a.empty()) {
            int f=a.top().second,level=a.top().first+1;
            a.pop();
            for (int i:arr) {
                int val=(i*f)%MOD;
                if (dist[val]>level) {
                    dist[val]=level;
                    a.push({level,val});
                }
            }
        }
        int res=dist[end];
        return (res==1e5)?-1:res;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends