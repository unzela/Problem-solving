//TC - adjacency list for undirected graph - O(2E)
//SC - O(2xE)

//TC - adjacency list for directed graph -  O(E)
//SC - O(E)
                
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m; //n = no of nodes, m = no of edges
    cin >> n >> m;
 
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); //Remove this for directed graph
    }
    return 0;
}