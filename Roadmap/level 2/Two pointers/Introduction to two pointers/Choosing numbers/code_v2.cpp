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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> mtr(n, vi(m));
    vi ptr(n, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int maxV = INT_MIN;

    FOR (i, 0, n) {
        FOR (j, 0, m) cin >> mtr[i][j];
        sort(mtr[i].begin(), mtr[i].end());
        pq.push({mtr[i][0], i});
        maxV = max(maxV, mtr[i][0]);
    }

    int ans = INT_MAX;

    while (1) {
        auto [minV, pos] = pq.top();
        pq.pop();
        ans = min(ans, maxV - minV);
        if (++ptr[pos] == m) break;
        pq.push({mtr[pos][ptr[pos]], pos});
        maxV = max(maxV, mtr[pos][ptr[pos]]);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
