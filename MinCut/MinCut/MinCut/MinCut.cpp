#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <vector>

#define V 6

int isReachable(std::vector<std::vector<int>> rGraph, int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    std::queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

void allReachableVertices(std::vector<std::vector<int>> rGraph, int s, bool visited[])
{
    visited[s] = true;
    for (int i = 0; i < V; i++)
        if (rGraph[s][i] && !visited[i])
            allReachableVertices(rGraph, i, visited);
}

void minCut(std::vector<std::vector<int>> graph, int s, int t)
{
    int u, v;
    std::vector<std::vector<int>> rGraph; rGraph.resize(graph.size());
    for (int i = 0; i < rGraph.size(); i++)
        rGraph[i].resize(rGraph.size());

    for (u = 0; u < graph.size(); u++)
        for (v = 0; v < graph.size(); v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    while (isReachable(rGraph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = std::min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
    }
    bool visited[V];
    memset(visited, false, sizeof(visited));
    allReachableVertices(rGraph, s, visited);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (visited[i] && !visited[j] && graph[i][j])
                std::cout << i << " - " << j << "\n";
}

int main()
{
    int n = 6;
    std::vector<std::vector<int>> graphTest =
    {                   {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
    };
    /*std::vector< std::vector<int>> graph;
    std::vector<std::vector<int>> matrix; matrix.resize(n);
    graph.push_back({ 0, 1, 16 });
    graph.push_back({ 0, 2, 13 });
    graph.push_back({ 1, 2, 10 });
    graph.push_back({ 2, 1, 4 });
    graph.push_back({ 1, 3, 12 });
    graph.push_back({ 2, 4, 14 });
    graph.push_back({ 3, 2, 9 });
    graph.push_back({ 3, 5, 20 });
    graph.push_back({ 4, 3, 7 });
    graph.push_back({ 4, 5, 4 });
    for (int i = 0; i < n; i++)
        matrix[i].resize(n);
    for (int i = 0; i < graph.size(); i++)
        matrix[graph[i][0]][graph[i][1]] = graph[i][2];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j) matrix[i][j] = 0;
            else if (!matrix[i][j]) matrix[i][j] = INF;
    */
    minCut(graphTest, 0, 5);
    return 0;
}