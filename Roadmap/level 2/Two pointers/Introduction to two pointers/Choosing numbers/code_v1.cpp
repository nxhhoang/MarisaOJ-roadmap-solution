#include <bits/stdc++.h>
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
const int MAXSIZE = 1e5;
const int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mtr(n, vector<int>(m));
    multiset<pii> st;
    vector<int> ptr(n, 0);

    FOR(i, 0, n) FOR(j, 0, m) cin >> mtr[i][j];
    FOR(i, 0, n) sort(all(mtr[i]));

    int ans = INT_MAX;
    
    for (int j = 0; j < n; j++) st.insert(make_pair(mtr[j][0], j));

    while (1) {
        ans = min(ans, st.rbegin()->first - st.begin()->first);
        int pos = st.begin()->second;
        st.erase(st.begin());
        if (++ptr[pos] == m) break;
        st.insert({mtr[pos][ptr[pos]], pos});
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
