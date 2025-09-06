// Space Complexity: O(n) - recursion stack
// fib_recursive.cpp 
#include <bits/stdc++.h>
using namespace std;

long long fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n-1) + fib_rec(n-2);
}

int main() {
    int n = 5;
    cout << "fib(" << n << ") = " << fib_rec(n) << "\n";
    return 0;
}