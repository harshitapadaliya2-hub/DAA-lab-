#include<bits/stdc++.h> 
using namespace std; 
bool DFS(vector<vector<int> >&adj,int src,int dest,int vis[]){ 
int n=adj.size(); 
if(src==dest) 
return true; 
vis[src]=1; 
for(int i=0;i<n;i++ ){ 
if(!vis[i] && adj[src][i]==1){ 
if(DFS(adj,i,dest,vis)) 
return true; 
} 
} 
return false; 
} 
int main(){ 
int n; 
cin>>n; 
vector<vector<int> >adj(n,vector<int>(n,0)); 
int u,v,src,dest; 
for(int i=0;i<n;i++){ 
for(int j=0;j<n;j++) 
cin>>adj[i][j]; 
} 
cin>>src>>dest; 
int vis[n]={0}; 
if(DFS(adj,src,dest,vis)){ 
cout<<"Yes Path Exists."; 
} 
else{ 
cout<<"No Such Path Exists"; 
} 
return 0; 
}
