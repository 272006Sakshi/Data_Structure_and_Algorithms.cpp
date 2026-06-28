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
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
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
