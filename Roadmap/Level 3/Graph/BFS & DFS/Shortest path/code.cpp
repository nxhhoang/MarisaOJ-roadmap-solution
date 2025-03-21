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
const int N = 10;
const int MAXSIZE = 1e5 + 1;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> com(n + 1, vi(1, MOD));
    queue<int> q;

    while(m--) {
        int a, b;
        cin >> a >> b;
        com[a].push_back(b);
        com[b].push_back(a);
    }
    com[1][0] = 0;

    for (int i = 1; i < n + 1; i++) {
        q.push(i);
        while(q.size()) {
            int val = q.front();
            for (int j = 1; j < com[val].size(); j++) {
                if (com[q.front()][0] + 1 < com[com[val][j]][0])
                    com[com[val][j]][0] = min(com[com[val][j]][0], com[q.front()][0] + 1),
                    q.push(com[val][j]);
            }
            q.pop();
        }
    }

    for (int i = 2; i < n + 1; i++) {
        if (com[i][0] == MOD) cout << -1 << " ";
        else cout << com[i][0] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
