// Time Complexity: O(log n * target_sum)
// Space Complexity: O(log n * target_sum)
#include <bits/stdc++.h>
using namespace std;

long long count_numbers_with_digit_sum(string n, int target_sum) {
    vector<vector<vector<long long>>> memo(n.length(), 
        vector<vector<long long>>(target_sum + 1, 
        vector<long long>(2, -1)));
    
    function<long long(int,int,int)> dp = [&](int pos, int sum_so_far, int tight) {
        if (pos == n.length()) return sum_so_far == target_sum ? 1LL : 0LL;
        
        if (memo[pos][sum_so_far][tight] != -1) 
            return memo[pos][sum_so_far][tight];
        
        int limit = tight ? (n[pos] - '0') : 9;
        long long result = 0;
        
        for (int digit = 0; digit <= limit; digit++) {
            if (sum_so_far + digit <= target_sum) {
                result += dp(pos + 1, sum_so_far + digit, 
                            tight && digit == limit);
            }
        }
        
        return memo[pos][sum_so_far][tight] = result;
    };
    
    return dp(0, 0, 1);
}

int main() {
    string n = "100";
    int target_sum = 1;
    cout << count_numbers_with_digit_sum(n, target_sum) << endl;
    return 0;
}