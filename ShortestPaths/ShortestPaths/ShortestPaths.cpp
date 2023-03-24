#include <iostream>
#include <fstream>
#include <limits.h>
#include<vector>
#include <stdlib.h>

const int MAX = 100000000;

int minDistance(std::vector<int> shPath, std::vector<bool> visited)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < shPath.size(); v++)
        if (visited[v] == false && shPath[v] <= min)
            min = shPath[v], min_index = v;
    return min_index;
}
void printSolution(std::vector<int> shPath)
{
    std::cout << "Vertex \t Distance from Source" << std::endl;
    for (int i = 0; i < shPath.size(); i++)
        std::cout << i << " \t" << shPath[i] << std::endl;
}

void dijkstra(std::vector<std::vector<int>>& matrix, int src)
{
    std::vector<int> shPath; shPath.resize(matrix.size());
    std::vector<bool> visited; visited.resize(matrix.size());

    for (int i = 0; i < matrix.size(); i++)
        shPath[i] = INT_MAX, visited[i] = false;

    shPath[src] = 0;

    for (int count = 0; count < matrix.size() - 1; count++) {
        int u = minDistance(shPath, visited);
        visited[u] = true;

        for (int v = 0; v < matrix.size(); v++) {
            if (!visited[v] && matrix[u][v]
                && shPath[u] != INT_MAX
                && shPath[u] + matrix[u][v] < shPath[v])
                shPath[v] = shPath[u] + matrix[u][v];
        }
    }
    printSolution(shPath);
}
void SetGraph(std::vector<std::vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        std::vector<int> row;
        for (int j = 0; j < n; j++) {
            std::string str;
            std::cin >> str;
            if (str == "-") {
                row.push_back(MAX);
            }
            else {
                row.push_back(atoi(str.c_str()));
            }
        }
        matrix.push_back(row);
    }
}
void printGraph(std::vector<std::vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
void FloydWarshallAlgorithm(std::vector<std::vector<int>>& matrix, int n) {
    std::vector<std::vector<int>> shPath;
    for (int i = 0; i < n; i++) {
        std::vector<int> arr;
        for (int j = 0; j < n; j++) {
            arr.push_back(matrix[i][j]);
        }
        shPath.push_back(arr);
    }
    for (int k = 0; k < n; k++) 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                shPath[i][j] = std::min(shPath[i][j], shPath[i][k] + shPath[k][j]);
    printGraph(shPath, n);
}

int main()
{
    std::cout << "enter the number of vertices \n";
    int n;
    std::cin >> n;
    std::vector< std::vector<int>> matrix;
    std::cout << "enter the graph matrix \n";
    SetGraph(matrix, n);
    std::cout << "enter the vertex from which the shortest path will be searched \n";
    int st; std::cin >> st;
    dijkstra(matrix, st);
    std::cout << "Floyd Result";
    FloydWarshallAlgorithm(matrix, n);
    

    return 0;
}