// Time Complexity: O(n*capacity)
// Space Complexity: O(n*capacity)
#include <bits/stdc++.h>
using namespace std;
int knapsack_01_recursive(int W, vector<int>& wt, vector<int>& val, int n, vector<vector<int>>& dp) {
    // Base case
    if (n == 0 || W == 0)
        return 0;

    // If already computed, return the stored value
    if (dp[n][W] != -1)
        return dp[n][W];

    // If weight of nth item is more than remaining capacity, skip it
    if (wt[n-1] > W)
        dp[n][W] = knapsack(W, wt, val, n-1, dp);
    else {
        // Include or exclude the item
        int includeItem = val[n-1] + knapsack(W - wt[n-1], wt, val, n-1, dp);
        int excludeItem = knapsack(W, wt, val, n-1, dp);
        dp[n][W] = max(includeItem, excludeItem);
    }

    return dp[n][W];
}

int knapsack_01(vector<int>& weights, vector<int>& values, int capacity,vector<vector<int>> &dp) {
    int n = weights.size();

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w],
                              dp[i-1][w-weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    return dp[n][capacity];
}

int main() {
    vector<int> weights = {1, 2, 3};
    vector<int> values = {60, 100, 120};
    int capacity = 5;
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    cout<< knapsack_01_recursive(capacity, weights, values, dp) << endl;
    cout << knapsack_01(weights, values, capacity) << endl;
    return 0;
}