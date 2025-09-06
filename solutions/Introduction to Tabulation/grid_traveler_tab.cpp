// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
#include <bits/stdc++.h>
using namespace std;

long long grid_traveler_tab(int m, int n) {
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
    dp[1][1] = 1;
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i + 1 <= m) dp[i+1][j] += dp[i][j];
            if (j + 1 <= n) dp[i][j+1] += dp[i][j];
        }
    }
    
    return dp[m][n];
}

int main() {
    int m = 3, n = 3;
    cout << grid_traveler_tab(m, n) << endl;
    return 0;
}