#include <iostream>

using namespace std;

#define V 5

bool isPathExist(int graph[V][V], int src, int dest, bool visited[])
{
    if (src == dest)
        return true;

    visited[src] = true;

    for (int i = 0; i < V; ++i)
    {
        if (graph[src][i] && !visited[i])
        {
            if (isPathExist(graph, i, dest, visited))
                return true;
        }
    }

    return false;
}

int main()
{
    int graph[V][V] =
    {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    int src;
    int dest;

    cout << "\nEnter Source Node --> ";
    cin >> src;
    cout << "Enter Destination Node --> ";
    cin >> dest;

    bool visited[V] = {false};

    if (isPathExist(graph, src, dest, visited))
    {
        cout << "\nPath Exists From Node " << src << " To Node " << dest << endl;
    }
    else
    {
        cout << "\nNo Path Exists From Node " << src << " To Node " << dest << endl;
    }

    return 0;
}