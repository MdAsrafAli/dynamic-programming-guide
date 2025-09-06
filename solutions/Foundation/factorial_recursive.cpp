// factorial_recursive.cpp
//Time Complexity: O(n)
//Space Complexity: O(n) - recursion stack
#include <bits/stdc++.h>
using namespace std;

long long factorial_rec(int n) {
    if (n <= 1) return 1;
    return n * factorial_rec(n-1);
}

int main() {
    int n = 10;
    cout << n << "! = " << factorial_rec(n) << "\n";
    return 0;
}