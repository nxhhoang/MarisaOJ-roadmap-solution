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
const int MAXN = 1e5 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve()
{
    string S;
    cin >> S;
    vector<int> dp(S.size(), 0);
    vector<int> now(S.size(), -1);
    vector<int> pre(S.size(), -1);
    int ans = S.size();
    int n = S.size();

    string fo=S.substr(0,1);
    string ba=S.substr(1);
    reverse(all(ba));
    int j = 0;
    for (int i = 1; i < S.size(); i++){
        if ((n - ans) / 2 > ba.size() || (n - ans) / 2 > fo.size()) break;
        int val = 0;
        int addr =- 1 ;
        for (int k = 0; k < ba.size(); k++) {
            if (ba[k] == fo[j]) {
                if (val + 1 > dp[k]) {
                    dp[k] = val + 1;
                    if (now[k] != -1) pre[k] = now[k];
                    now[k] = addr;
                } else val = dp[k], addr = k;
            } else {
                if (val <= dp[k]) {
                    val = dp[k];
                    addr = k;
                }
            }
        }
        // cout << fo << " " << ba << endl;
        for (int k = 0; k < ba.size(); k++) {
            // cout << dp[k] << endl;
            if (k == ba.size() - 1) ans = min(ans, n - 2 * dp[k]), dp[k] = 0, now[k] = -1, pre[k] = -1;
            else if (k == ba.size() - 2) ans = min(ans, n - 2 * dp[k] - 1);
            if (now[k] == ba.size() - 1) {
                now[k] = pre[k];
                if (pre[k] != -1) {
                    dp[k] = dp[pre[k]] + 1;
                    pre[k] = -1;
                }
            }
        }
        ba.pop_back();
        fo.push_back(S[i]);
        j++;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
