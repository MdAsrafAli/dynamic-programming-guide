// grid_traveler.cpp
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
#include <bits/stdc++.h>
using namespace std;

long long grid_traveler(int m, int n, map<string, long long>& memo) {
    string key = to_string(m) + "," + to_string(n);
    if (memo.find(key) != memo.end()) return memo[key];
    if (m == 1 && n == 1) return 1;
    if (m == 0 || n == 0) return 0;
    
    memo[key] = grid_traveler(m-1, n, memo) + grid_traveler(m, n-1, memo);
    return memo[key];
}

int main() {
    int m = 3, n = 3;
    map<string, long long> memo;
    cout << grid_traveler(m, n, memo) << endl;
    return 0;
}