#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define vi vector<int>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    if (m != n - 1) {
        cout << "NO" << endl;
        return;
    }
    if (n == 1 && m == 0) {
        cout << "YES" << endl;
        return;
    }
 
    vector<vi> com(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u == v) {
            cout << "NO" << endl;
            return;
        }
        com[u].pb(v);
        com[v].pb(u);
    }
 
    vector<bool> visited(n + 1, false);
    queue<int> qp;
    qp.push(1);
    visited[1] = true;

    while (!qp.empty()) {
        int val = qp.front();
        qp.pop();
        for (int neighbor : com[val]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                qp.push(neighbor);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
