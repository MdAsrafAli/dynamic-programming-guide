// Time Complexity: O(m*n)
// Space Complexity: O(m*n) -> Can be optimized to O(n)
#include <bits/stdc++.h>
using namespace std;
int paths_recursive(int i, int j, int m, int n){
    if(i==m-1 and j==n-1)return 1;
    if(i==m or j==n)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    return dp[i][j] = paths(i+1,j,m,n)+paths(i,j+1,m,n);
}

int unique_paths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[m-1][n-1];
}

int main() {
    int m = 3, n = 7;
    vector<vector<int>>dp(m, vector<int>(n,-1));
    cout << paths_recursive(0, 0, m, n) <<endl;
    cout << unique_paths(m, n) << endl;
    return 0;
}
