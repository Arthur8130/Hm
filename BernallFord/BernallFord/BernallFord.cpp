#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

const int INF = 1000000000;

void SetGraph(vector<vector<int>>& adj, int n) {
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            string tmp;
            cin >> tmp;
            if (tmp == "-") {
                row.push_back(INF);
            }
            else {
                row.push_back(atoi(tmp.c_str()));
            }
        }
        adj.push_back(row);
    }
}
vector<int> BellmanFord(vector<vector<int>>& adj, int n, int start) {
    vector<int> distances(n, INF);
    distances[start] = 0;
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distances[j] + adj[j][i] < distances[i])
                    distances[i] = distances[j] + adj[j][i];
            }
        }
    }
    return distances;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj;
    SetGraph(adj, n);

    vector<int> BellmanFordResult;
    BellmanFordResult = BellmanFord(adj, n, 0);

    for (int i = 0; i < n; i++) {
        cout << BellmanFordResult[i] << ' ';
    }
    return 0;
}