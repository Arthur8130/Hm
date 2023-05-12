#include <iostream>
#include <vector>
#include <cstring>

const int N = 1000;

std::vector<int> g[N];
int match[N];
bool visited[N];

bool search(int k) {
    visited[k] = true;
    for (int i = 0; i < g[k].size(); i++) {
        int u = g[k][i];
        int w = match[u];
        if (w == -1 || (!visited[w] && search(w))) {
            match[u] = k;
            return true;
        }
    }
    return false;
}

int kun(int n) {
    memset(match, -1, sizeof(match));
    int res = 0;
    for (int v = 0; v < n; v++) {
        memset(visited, false, sizeof(visited));
        if (search(v)) {
            res++;
        }
    }
    return res;
}

int main() {
    int n = 8, m = 15;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = kun(n);

    std::cout << "Result: ";
    for (int i = 0; i < n; i++) {
        if (match[i] != -1) {
            std::cout << i << "-" << match[i] << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}

