// climb_stairs.cpp
// Time Complexity: O(n)
// Space Complexity: O(n) -> Can be optimized to O(1)
#include <bits/stdc++.h>
using namespace std;

int climb_stairs(int n) {
    if (n <= 2) return n;
    
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

// Space optimized version
int climb_stairs_optimized(int n) {
    // Space Complexity: O(1)
    if (n <= 2) return n;
    
    int prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; i++) {
        int current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
}

int main() {
    int n = 5;
    cout << climb_stairs(n) << endl;
    cout << climb_stairs_optimized(n) << endl;
    return 0;
}