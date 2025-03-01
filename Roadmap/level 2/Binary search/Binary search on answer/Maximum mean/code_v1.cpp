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
    vector<int> arr(n);
    vector<ll> pre(n + 1, 0);
    vector<double> ktr(n + 1, 0);
    vector<double> minK(n + 1, INT_MAX);
    FOR(i, 0, n) cin >> arr[i], pre[i + 1] = pre[i] + arr[i];

    double l = 1;
    double r = 1e9 + 1;
    for (int j = 0; j <= 60; j++) {
        double mid = l + (r - l) / 2;
        for (int i = 1; i <= n; i++) ktr[i] = pre[i] - mid * i;
        bool flag = 0;
        double minV = ktr[n];
        for (int i = n; i >= k; i--) {
            minV = max(minV, ktr[i]);
            minK[i] = minV;
        }
        for (int i = 1; i <= n - k; i++) {
            if (ktr[i] < minK[i + k]) {
                flag = 1;
                break;
            }
        }
        if (flag) l = mid;
        else r = mid;        
    }
    cout << fixed << setprecision(3) << r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t; LLLLLLLLLLLLLLLLLLLLL
    while(t--){
        solve();
    }
    return 0;
}
