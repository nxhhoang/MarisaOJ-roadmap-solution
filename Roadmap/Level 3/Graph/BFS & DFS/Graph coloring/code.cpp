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
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, q;
vector<vi> tre(MSIZE);
vector<pii> ud(MSIZE);
vector<int> col(MSIZE);
vector<int> res(MSIZE, 0);
vector<int> maxD(MSIZE, -1);

void solve()
{
    cin >>  n >> m;

    for (int i =0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        tre[u].push_back(v);
        tre[v].push_back(u);
    }
    cin >> q;
    for (int j = q - 1; j >= 0; j--) {
        cin >> ud[j].first >> ud[j].second >> col[j];
    }

    queue<pii> st;
    for (int i = 0; i < q; i++) {
        vector<bool> visited(MSIZE, 0);
        int c = col[i];

        st.push({ud[i].first, ud[i].second});
        visited[ud[i].first] = 1;
        while (st.size()) {
            auto [u, d] = st.front();
            st.pop();

            if (d <= maxD[u]) continue;
            else maxD[u] = d;

            if (res[u] == 0) res[u] = c;
            if (d == 0) continue;

            for (int j = 0; j < tre[u].size(); j++) {
                int ve = tre[u][j];
                if (visited[ve]) continue;
                visited[ve] = 1;
                st.push({ve, d - 1});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << endl;
    }
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
