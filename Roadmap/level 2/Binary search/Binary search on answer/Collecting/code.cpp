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
    vector<pii> arr(n);
    FOR(i, 0, n) cin >> arr[i].first >> arr[i].second;
    
    double l = 1;
    double r = 1e9 + 1;
    for (int j = 0; j <= 45; j++) {
        double mid = l + (r - l) / 2;
        vector<double> kq(n);
        for (int i = 0; i < n; i++) kq[i] = arr[i].first - mid * arr[i].second;
        priority_queue<double> pq(kq.begin(), kq.end());
        double sum = 0;
        for (int i = 0; i < k; i++) sum += pq.top(), pq.pop();
        if (sum <= 0) r = mid;
        else l = mid;
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
