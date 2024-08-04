//Given an undirected graph, return a vector of all nodes by traversing the graph using breadth-first search (BFS)
//TC - O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.
//SC - O(3N) ~ O(N), Space for queue data structure visited array and an adjacency list

#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0}; 
    vis[0] = 1; 
    queue<int> q;
    q.push(0);  // Push the initial starting node 
    vector<int> bfs; 

    while(!q.empty()) {

        int node = q.front(); 
        q.pop(); 
        bfs.push_back(node); 
      
        for(auto it : adj[node]) { // Traverse for all its neighbours 
            if(!vis[it]) { // If the neighbour has previously not been visited, store in Q and mark as visited 
                vis[it] = 1; 
                q.push(it); 
            }
        }
    }
    return bfs; 
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
    vector <int> adj[6];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    vector <int> ans = bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}
