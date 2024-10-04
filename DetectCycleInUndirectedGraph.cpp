#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph
{
    int V;          // Number of vertices
    list<int> *adj; // Pointer to an array for adjacency list

    // A recursive function to detect cycle in a graph
    bool isCyclicUtil(int v, vector<bool> &visited, int parent)
    {
        visited[v] = true;

        // Traverse all the vertices adjacent to this vertex
        for (auto i : adj[v])
        {
            // If an adjacent vertex is not visited yet, then recursively visit it
            if (!visited[i])
            {
                if (isCyclicUtil(i, visited, v))
                {
                    return true;
                }
            }
            // If an adjacent vertex is visited and is not the parent of current vertex, then there is a cycle
            else if (i != parent)
            {
                return true;
            }
        }
        return false;
    }

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v); // Since the graph is undirected
    }

    // Function to detect cycle
    bool isCyclic()
    {
        vector<bool> visited(V, false);

        // Run a DFS from each unvisited vertex to detect a cycle
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (isCyclicUtil(i, visited, -1))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    if (g.isCyclic())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
