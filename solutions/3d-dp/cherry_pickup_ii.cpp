// Time Complexity: O(m * n^2)
// Space Complexity: O(m * n^2)
#include <bits/stdc++.h>
using namespace std;

int cherry_pickup_ii(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    map<tuple<int,int,int>, int> dp;
    
    function<int(int,int,int)> dfs = [&](int r, int c1, int c2) {
        if (r == m) return 0;
        if (dp.find({r, c1, c2}) != dp.end()) return dp[{r, c1, c2}];
        
        int cherries = grid[r][c1] + (c1 != c2 ? grid[r][c2] : 0);
        int max_cherries = 0;
        
        for (int nc1 = c1-1; nc1 <= c1+1; nc1++) {
            for (int nc2 = c2-1; nc2 <= c2+1; nc2++) {
                if (nc1 >= 0 && nc1 < n && nc2 >= 0 && nc2 < n) {
                    max_cherries = max(max_cherries, dfs(r+1, nc1, nc2));
                }
            }
        }
        
        dp[{r, c1, c2}] = cherries + max_cherries;
        return dp[{r, c1, c2}];
    };
    
    return dfs(0, 0, n-1);
}

int main() {
    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    cout << cherry_pickup_ii(grid) << endl;
    return 0;
}