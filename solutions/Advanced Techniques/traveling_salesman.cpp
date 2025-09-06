// Time Complexity: O(n^2 * 2^n)
// Space Complexity: O(n * 2^n)
#include <bits/stdc++.h>
using namespace std;

int traveling_salesman(vector<vector<int>>& dist) {
    int n = dist.size();
    int all_visited = (1 << n) - 1;
    map<pair<int,int>, int> memo;
    
    function<int(int,int)> dp = [&](int curr, int mask) {
        if (mask == all_visited) return dist[curr][0];
        
        if (memo.find({curr, mask}) != memo.end()) 
            return memo[{curr, mask}];
        
        int ans = INT_MAX;
        for (int city = 0; city < n; city++) {
            if ((mask & (1 << city)) == 0) {
                int new_mask = mask | (1 << city);
                int distance = dist[curr][city] + dp(city, new_mask);
                ans = min(ans, distance);
            }
        }
        
        memo[{curr, mask}] = ans;
        return ans;
    };
    
    return dp(0, 1);
}

int main() {
    vector<vector<int>> dist = {{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}};
    cout << traveling_salesman(dist) << endl;
    return 0;
}