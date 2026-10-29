#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

void dijkstra(int start, int destination,
              vector<vector<pair<int, int> > >& graph, int n)
{
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);

    priority_queue<pair<int, int>,
                   vector<pair<int, int> >,
                   greater<pair<int, int> > > pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;
            

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    if (dist[destination] == INT_MAX)
    {
        cout << "No delivery route exists.\n";
        return;
    }

    vector<int> path;

    for (int v = destination; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "\nShortest Delivery Route: ";

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];

        if (i != path.size() - 1)
            cout << " -> ";
    }

    cout << "\nMinimum Distance: "
         << dist[destination] << " km\n";
}

int main()
{
    int n, roads;

    cout << "Enter number of locations: ";
    cin >> n;

    vector<vector<pair<int, int> > > graph(n);

    cout << "Enter number of roads: ";
    cin >> roads;

    cout << "Enter roads (location1 location2 distance):\n";

    for (int i = 0; i < roads; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int start, destination;

    cout << "Enter distribution center: ";
    cin >> start;

    cout << "Enter customer location: ";
    cin >> destination;

    dijkstra(start, destination, graph, n);

    return 0;
}
