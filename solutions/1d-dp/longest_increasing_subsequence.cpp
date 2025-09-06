// longest_increasing_subsequence.cpp
// Time Complexity: O(n^2)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

int lis_recursive(int i, vector<int>& a,vector<int>& dp){
    if(dp[i] != -1) return dp[i];
    int ans = 1;
    for(int j = 0;j < i; j++){
        if(a[i] > a[j]){
            ans = max(ans, lis(j, a, dp)+1);
        }
    }
    return dp[i] = ans;
}

int longest_increasing_subsequence(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int n = nums.size();
    vector<int> dp(n, 1);
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n=nums.size();
    vector<int>dp(n,-1);
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,lis_recursive(i,nums,dp));
    }
    cout<< ans <<endl;
    cout << longest_increasing_subsequence(nums) << endl;
    return 0;
}