//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<string> all_longest_common_subsequences(string X, string Y) {
        int n=X.size(),m=Y.size();
        int L[n+1][m+1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) 
                    L[i][j] = 0;
                else if (X[i - 1] == Y[j - 1]) 
                    L[i][j] = L[i - 1][j - 1] + 1;
                else
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
        set<string> ans;
        stack<pair<pair<int,int>,string>> stk;
        stk.push({{n,m},""});
        unordered_set<string> visited;
        while (!stk.empty()) {
            int x = stk.top().first.first;
            int y = stk.top().first.second;
            string str = stk.top().second;
            stk.pop();
            
            string state = to_string(x) + "," + to_string(y) + "," + str;
            if (visited.count(state)) continue;
            visited.insert(state);
    
            if (x == 0 || y == 0) {
                ans.insert(str);
            } else {
                if (X[x - 1] == Y[y - 1]) {
                    stk.push({{x - 1, y - 1}, X[x - 1] + str});
                } else {
                    if (L[x - 1][y] >= L[x][y - 1]) stk.push({{x - 1, y}, str});
                    if (L[x - 1][y] <= L[x][y - 1]) stk.push({{x, y - 1}, str});
                }
            }
        }
        vector<string> res;
        for (string i:ans) res.push_back(i);
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends