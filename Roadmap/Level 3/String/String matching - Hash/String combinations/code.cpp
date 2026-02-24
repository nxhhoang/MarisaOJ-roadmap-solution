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
#define vll vector<ll>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int MAXSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve()
{
    int n;
    cin >> n;
    string s, c;
    cin >> s;
    vector<pii> val;
    vector<int> dp(s.size() + 1, 0);

    for (int d = 0; d < n; d++) {
        cin >> c;
        int m = c.size();
        string t = c + "#" + s;
        vector<int> KMP(t.size(), 0);
        int cnt = 0, j = 0;
        for (int i = 1; i < t.size(); i++) {
            j = KMP[i - 1];
            while(j > 0 && t[j] != t[i]) j = KMP[j - 1];
            if (t[i] == t[j]) j++;
            KMP[i] = j;
            if (KMP[i] == m) val.push_back({i - m - KMP[i], m});
        }
    }
    // for (int i = 0; i < val.size(); i++) cout << val[i].first << "  " << val[i].second << endl;

    sort(all(val));
    int maxV = 0;
    for (int i = 0; i < val.size(); i++) {
        dp[val[i].first + val[i].second] = max(dp[val[i].first] + val[i].second, dp[val[i].first + val[i].second]);
        maxV = max(dp[i], maxV);
    }
    for (int i = 0; i < dp.size(); i++) maxV = max(maxV, dp[i]);
    cout << maxV;
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
