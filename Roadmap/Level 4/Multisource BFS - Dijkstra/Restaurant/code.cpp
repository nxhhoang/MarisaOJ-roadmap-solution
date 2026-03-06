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
vector<vector<pii>> tre(MSIZE);
vector<int> arr(MSIZE);
vector<vector<ll>> val(51, vector<ll>(MSIZE, LLONG_MAX / 4));
vector<priority_queue<pll, vector<pll>, greater<pll>>> pq(51);

void solve()
{   
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i], val[arr[i]][i] = 0, pq[arr[i]].push({0, i});
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        tre[a].push_back({b, w});
        tre[b].push_back({a, w});
    }

    for (int i = 1; i <= k; i++) {
        while (pq[i].size()) {
            auto [pa, ve] = pq[i].top();
            pq[i].pop();

            if (pa > val[i][ve]) continue;
            for (auto &[v, w] : tre[ve]) {
                if (val[i][v] > pa + w) {
                    val[i][v] = pa + w;
                    pq[i].push({val[i][v], v});
                }
            }
        }
    }

    ll minV = LLONG_MAX / 4;
    int dinh = 1;
    for (int i = 1; i <= n; i++) {
        ll sum = 0;
        for (int j = 1; j <= k; j++) {
            if (val[j][i] == LLONG_MAX / 4) {
                sum = LLONG_MAX;
                break;
            }
            sum += val[j][i];    
        }
        
        if (sum < minV) minV = sum, dinh = i;
    }
    cout << dinh;
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
