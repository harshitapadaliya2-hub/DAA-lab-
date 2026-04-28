#include <bits/stdc++.h> 
using namespace std; 
bool DFS(int node, int col, vector<int> &color, vector< vector< 
int > > &adj) { 
color[node] = col; 
for (int neighbor : adj[node]) { 
if (color[neighbor] == -1) { 
if (!DFS(neighbor, !col, color, adj)) { 
return false; 
} 
} else if (color[neighbor] == col) { 
return false; 
} 
} 
return true; 
} 
int main() { 
int n; 
cin >> n; 
vector<vector<int>> adjMatrix(n, vector<int>(n)); 
for (int i = 0; i < n; ++i) { 
for (int j = 0; j < n; ++j) { 
cin >> adjMatrix[i][j]; 
} 
} 
// Convert adjacency matrix to adjacency list 
vector<vector<int>> adj(n); 
for (int i = 0; i < n; ++i) { 
for (int j = 0; j < n; ++j) { 
if (adjMatrix[i][j] == 1) { 
adj[i].push_back(j); 
} 
} 
} 
vector<int> color(n, -1); 
for (int i = 0; i < n; ++i) { 
if (color[i] == -1) { 
if (!DFS(i, 0, color, adj)) { 
cout << "Not Bipartite.\n"; 
return 0; 
} 
} 
} 
cout << "Yes Bipartite.\n"; 
return 0; 
} 
