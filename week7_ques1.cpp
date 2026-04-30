using namespace std; 
typedef pair<int, int> pii; // {distance, vertex} 
void printPath(vector<int>& parent, int vertex, int source) { 
if (vertex == source) { 
cout << source + 1 << " : "; 
return; 
} 
printPath(parent, parent[vertex], source); 
cout << vertex + 1 << " "; 
} 
void dijkstra(vector<vector<pii>>& graph, int V, int source) { 
vector<int> dist(V, INT_MAX); 
vector<int> parent(V, -1); 
priority_queue<pii, vector<pii>, greater<pii>> pq; // min- 
heap  
dist[source] = 0; 
pq.push({0, source}); 
while (!pq.empty()) { 
int u = pq.top().second; 
int current_dist = pq.top().first; 
pq.pop(); 
if (current_dist > dist[u]) continue; // Skip if a 
shorter path is already found 
for (auto& edge : graph[u]) { 
int v = edge.first; 
int weight = edge.second; 
if (dist[u] + weight < dist[v]) { 
dist[v] = dist[u] + weight; 
parent[v] = u; 
pq.push({dist[v], v}); 
} 
} 
} 
// Print the shortest paths 
for (int i = 0; i < V; ++i) { 
if (i == source) { 
cout << source + 1 << " : 0" << endl; 
continue; 
} 
if (dist[i] == INT_MAX) { 
cout << "No path from " << source + 1 << " to " << i 
+ 1 << endl; 
continue; 
} 
printPath(parent, i, source); 
cout << ": " << dist[i] << endl; 
} 
} 
int main() { 
int V; 
cin >> V; 
vector<vector<pii>> graph(V); 
for (int i = 0; i < V; ++i) { 
for (int j = 0; j < V; ++j) { 
int weight; 
cin >> weight; 
if (weight != 0) { 
graph[i].push_back({j, weight}); 
} 
} 
} 
int source; 
cin >> source; 
source--; // converting to 0-based index 
dijkstra(graph, V, source); 
return 0; 
}
