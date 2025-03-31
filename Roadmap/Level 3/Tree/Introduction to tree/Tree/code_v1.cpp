#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define ub upper_bound
#define lb lower_bound

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MAXSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> com(n + 1, vi(1, 0));
    queue<int> qp;
    if (m != n - 1) {
        cout << "NO" << endl;
        return;
    }
    if (n == 1 && m == 0) {
        cout << "YES" << endl;
        return;
    }
 
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (u == v) {
            cout << "NO" << endl;
            return;
        }   
        com[v].push_back(u);
        com[u].push_back(v);
    }
 
    qp.push(1);
    while(qp.size()) {
        int val = qp.front();
        for (int j = 1; j < com[val].size(); j++) {
            if (com[com[val][j]][0] == 0) {
                com[com[val][j]][0] = val;
                qp.push(com[val][j]);
            }
        }
        qp.pop();
    }

    for (int i = 1; i < n + 1; i++) if (com[i][0] == 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
