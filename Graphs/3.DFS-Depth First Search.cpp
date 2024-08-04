//Given an undirected graph, return a vector of all nodes by traversing the graph using depth-first search (DFS).
//TC - For an undirected graph, O(N) + O(2E)
//TC - For a directed graph, O(N) + O(E), Because for every node we are calling the recursive function once, the time taken is O(N) 
//and 2E is for total degrees as we traverse for all adjacent nodes.
//SC - O(3N) ~ O(N), Space for dfs stack space, visited array and an adjacency list.

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
    vis[node] = 1; 
    ls.push_back(node); 

    for(auto it : adj[node]) { // Traverse all its neighbours
        if(!vis[it]) {
            dfs(it, adj, vis, ls); 
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0}; 
    int start = 0;
    vector<int> ls; // List to store dfs

    dfs(start, adj, vis, ls); // Call dfs for starting node
    return ls; 
}

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    vector <int> adj[5];
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    vector <int> ans = dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}
