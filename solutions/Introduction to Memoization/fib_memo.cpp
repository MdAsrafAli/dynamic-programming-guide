// fib_memo.cpp
// Time Complexity: O(n)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

long long fib_memo(int n, vector<long long>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fib_memo(n-1, memo) + fib_memo(n-2, memo);
}

int main() {
    int n = 50;
    vector<long long> memo(n+1, -1);
    cout << "fib(" << n << ") = " << fib_memo(n, memo) << "\n";
    return 0;
}