// nxhhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define endl '\n'
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
const int MAXSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i], vec[i] *= vec[i];

    double l = 0.0001;
    double r = MOD;
    for (int i = 0; i < 60; i++) {
        double mid = (l + r) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; i++) cnt += floor(vec[i] / mid);
        if (cnt >= k) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(3) << l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
