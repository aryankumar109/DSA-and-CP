#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        
        int root = min_element(deg.begin(), deg.end()) - deg.begin();
        vector<int> path = {root};
        vector<int> visited(n, 0);
        visited[root] = 1;
        
        for (int i = 0; i < path.size(); ++i) {
            int node = path[i];

            if (path.size() >= 2 && deg[path.back()] == deg[root]) {
                break;
            }

            sort(adj[node].begin(), adj[node].end(), [&](int a, int b) {
                return deg[a] < deg[b];
            });

            for (int nei : adj[node]) {
                if (!visited[nei]) {
                    path.push_back(nei);
                    visited[nei] = 1;
                    break;
                }
            }
        }

        int cols = path.size();
        int rows = n / cols;
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        ans[0] = path;

        for (int r = 1; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                for (int nei : adj[ans[r-1][c]]) {
                    if (!visited[nei]) {
                        ans[r][c] = nei;
                        visited[nei] = 1;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
