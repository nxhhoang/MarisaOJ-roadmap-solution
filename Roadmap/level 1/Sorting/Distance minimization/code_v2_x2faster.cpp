#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using namespace std;
using ll = long long;

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> u(n);
    vector<int> v(n);
    FOR(i, 0, n) cin >> u[i] >> v[i];
    nth_element(u.begin(), u.begin() + n/2, u.end());
	nth_element(v.begin(), v.begin() + n/2, v.end());
    ll sum = 0;
    FOR(i, 0, n) sum += abs(u[i] - u[n / 2]) + abs(v[i] - v[n / 2]);
    cout << sum << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
