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

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MOD = 1e9 + 7;

pair<int, int> AB[MAXSIZE];
int B[MAXSIZE + 1];

void solve()
{
    int n;
    cin >> n;

    FOR(i, 0, n) cin >> AB[i].fi;
    FOR(i, 0, n) cin >> AB[i].se;
    sort(AB, AB + n);
    for(int i = 1; i <= n; i++) B[i] = max(B[i - 1], AB[i - 1].second);

    cout << B[n] << " ";
    int maxV = INT_MIN;
    ll total = 0;

    for (int i = n - 1; i >= 1; i--)
    {
        total += AB[i].first;
        maxV = max(AB[i].second - AB[i].first, maxV);
        cout << max(total + B[i], total + maxV + AB[i - 1].first) << " ";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
