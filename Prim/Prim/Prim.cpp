#include <iostream>
#include<vector>

const int INF = 99999999;
void InputGraph(std::vector<std::vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        std::vector<int> r;
        for (int j = 0; j < n; j++) {
            std::string tmp;
            std::cin >> tmp;
            if (tmp == "-") r.push_back(INF);
            else r.push_back(atoi(tmp.c_str()));
        }
        matrix.push_back(r);
    }
}
int minKey(std::vector<int> key, std::vector<bool> visited, int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (visited[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}
void printPrim(std::vector<int> p, std::vector<std::vector<int>> graph)
{
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < graph.size(); i++)
        std::cout << p[i] << " - " << i << " \t"
        << graph[i][p[i]] << " \n";
}

void Prim(std::vector<std::vector<int>> graph)
{
    std::vector<int> p; p.resize(graph.size());
    std::vector<int> key; key.resize(graph.size());

    std::vector<bool> visited; visited.resize(graph.size());
    for (int i = 0; i < graph.size(); i++)
        key[i] = INT_MAX, visited[i] = false;

    key[0] = 0;
    p[0] = -1;
    for (int count = 0; count < graph.size() - 1; count++) {
        int u = minKey(key, visited, graph.size());
        visited[u] = true;
        for (int v = 0; v < graph.size(); v++)
            if (graph[u][v] && visited[v] == false
                && graph[u][v] < key[v])
                p[v] = u, key[v] = graph[u][v];
    }
    printPrim(p, graph);
}
int main()
{
    std::cout << "enter the number of vertices \n";
    int n;
    std::cin >> n;
    std::vector< std::vector<int>> matrix;
    std::cout << "enter the graph matrix \n";
    InputGraph(matrix, n);
    Prim(matrix);
    return 0;
}