// nxhhoang - the dreamer
// g++ -std=c++11 -Wall -Wextra -O2 B.cpp -o B.exe
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define ub upper_bound // find target < min(value)
#define lb lower_bound // find target <= min(value)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MSIZE = 1e5 + 5;
const int MAXN = 2e5 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, k;
vector<int> val(MSIZE, 0);
vector<vi> tre(MSIZE);
priority_queue<pii> pq;
int cnt = 0;

void solve()
{   
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        tre[a].push_back(b);
        tre[b].push_back(a);
    }    
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        pq.push({b + 1, a});
        val[a] = b + 1;
    }
    while (pq.size()) {
        auto [pa, ve] = pq.top();
        pq.pop();
        if (pa < val[ve]) continue;

        for (auto &v : tre[ve]) {
            if (val[v] < pa - 1) {
                val[v] = pa - 1;
                pq.push({val[v], v});
            }
        }
    }
    for (int i = 1; i<=n; i++) if (val[i])cnt++;
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t; // DLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
    while (t--)
    {
        solve();
    }
    return 0;
}
