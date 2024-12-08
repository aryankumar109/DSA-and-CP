#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

vector<int> visited;
int cnt, even, x;

void dfsprint(int root, int parent, vector<vector<int>>& graph) {
    visited[root] = 1;
    for (int i = 0; i < graph[root].size(); i++) {
        if (visited[graph[root][i]] == 0) {
            dfsprint(graph[root][i], root, graph);
        }
    }

    if (even && cnt < 2) {
        x = parent;
        cnt++;
    } else {
        x = root;
    }
    
    if (parent > 0)
        cout << parent << " " << root << " " << x << endl;

    return;
}

void solve() {
    int n = 0, a, b;
    cin >> n;
    visited = vector<int>(n + 1, 0);
    vector<vector<int>> graph(n + 1);
    x = 0;
    cnt = 0;

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if (n % 2 == 1) {
        even = 0;
        cout << 0 << endl;
        dfsprint(1, -1, graph);
        return;
    } else {
        even = n - 1;
        if (n > 2) {
            cout << 0 << endl;
            dfsprint(1, -1, graph);
        } else {
            cout << 1 << endl;
            dfsprint(1, -1, graph);
        }
    }

    return;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
