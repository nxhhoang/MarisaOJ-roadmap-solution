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

inline int log1110(int x) {return log((double)x)/log(11.0f/10);} 

void solve()
{
    int n;
    cin >> n;

    vector<int> pos(n);
    vector<pii> brr(n);
    vector<int> dp(n, 0);
    
    for (int i = 0; i < n; i++) cin >> brr[i].first, brr[i].second = i;
    sort(all(brr), [](const pii &a, const pii &b) {return a.first < b.first || (a.first == b.first && a.second < b.second);});
    int old = brr[0].first;
    int cur = 0;
    int cnt = -1;
    for (int i = 0; i < n; i++) {
        if (old != brr[i].first) old = brr[i].first, cur = i - cnt;
        else cnt++;
        pos[brr[i].second] = cur;
    }
    int m = n - cnt;
    vector<int> che(log1110(m) + 5);
    int d = 0;
    double l5 = 11;
    double l4 = 10;
    che[d++] = 0;
    while (l5 <= m * l4) che[d++] = (l5 / l4), l5 *= 11, l4 *= 10;
    if (che[d - 1] != m - 1) che[d++] = m - 1;

    for (int i = 0; i < pos.size(); i++) {
        int val = 0, cnt = pos[i];
        int j = che[log1110(cnt + 1)]; 
        if (cnt == j && log1110(i + 1) > 0) j = che[log1110(cnt + 1) - 1];
        for (; j < cnt; j++) val = max(dp[j], val);
        if (cnt) dp[cnt] = max(dp[cnt], max(dp[cnt - 1], val) + 1);
        else dp[cnt] = max(dp[cnt], val + 1);
        for (int k = 0; k < d; k++) {
            int gdf = che[k];
            if (gdf >= cnt) {
                if (dp[gdf] <= dp[cnt]) dp[gdf] = dp[cnt];
                else break;
            }
        }
    }
    cout << *max_element(all(dp));
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
