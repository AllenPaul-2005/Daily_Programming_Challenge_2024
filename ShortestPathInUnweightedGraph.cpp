#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findShortestPath(int V, vector<vector<int>> &edges, int start, int end)
{
    vector<vector<int>> adj(V);
    for (auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<int> distance(V, -1);
    queue<int> q;

    distance[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node])
        {
            if (distance[neighbor] == -1)
            {
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);

                if (neighbor == end)
                {
                    return distance[neighbor];
                }
            }
        }
    }

    return -1; // If no path found
}

int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
    int start = 0, end = 4;

    int shortestPath = findShortestPath(V, edges, start, end);
    if (shortestPath != -1)
    {
        cout << "Output: " << shortestPath << endl;
    }
    else
    {
        cout << "No path found." << endl;
    }

    return 0;
}
