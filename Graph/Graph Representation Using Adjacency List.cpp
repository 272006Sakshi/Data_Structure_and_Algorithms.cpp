#include <iostream>
#include <list>
#include <map>
using namespace std;

class Graph {
    map<int, vector<int>>adj; 
public:
    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        // Add edge from v to u 
        // undirected
        adj[v].push_back(u);
    }

    void print()
    {
        // Iterate over each vertex
        for (auto i : adj) {
            // Print the vertex
            cout << i.first << " -> ";
            // Iterate over the connected vertices
            for (auto j : i.second) {
                // Print the connected vertex
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.add_edge(1, 0);
    g.add_edge(2, 0);
    g.add_edge(1, 2);

    g.print();
    return 0;
}
