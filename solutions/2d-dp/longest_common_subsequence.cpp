// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
#include <bits/stdc++.h>
using namespace std;

int longest_common_subsequence_recursive(int i,int j,string &a,string &b, dp){
        if(i < 0 or j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans=lcs(i-1, j, a, b);
        ans=max(ans,lcs(i, j-1, a, b));
        ans=max(ans,lcs(i-1, j-1, a, b)+(a[i]==b[j]));

        return dp[i][j]=ans;
    }

int longest_common_subsequence(string text1, string text2) {
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    string text1 = "abcde", text2 = "ace";
    int m = text1.length(), n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    cout << longest_common_subsequence(n-1, m-1, text1, text2, dp) << endl;

    cout << longest_common_subsequence(text1, text2) << endl;
    return 0;
}