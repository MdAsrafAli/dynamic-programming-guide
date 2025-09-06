// Time Complexity: O(n)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

int diameter_of_tree(vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> graph;
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    int diameter = 0;
    
    function<int(int,int)> dfs = [&](int node, int parent) {
        int max1 = 0, max2 = 0;
        for (int child : graph[node]) {
            if (child != parent) {
                int depth = dfs(child, node);
                if (depth > max1) {
                    max2 = max1;
                    max1 = depth;
                } else if (depth > max2) {
                    max2 = depth;
                }
            }
        }
        
        diameter = max(diameter, max1 + max2);
        return max1 + 1;
    };
    
    dfs(0, -1);
    return diameter;
}

int main() {
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{3,4}};
    cout << diameter_of_tree(edges) << endl;
    return 0;
}