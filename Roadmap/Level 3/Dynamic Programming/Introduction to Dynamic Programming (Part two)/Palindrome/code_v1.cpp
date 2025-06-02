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
    int ans = S.size();
    int n = S.size();

    string fo="";
    string ba=S;
    reverse(all(ba));
    for (int i = 0; i < S.size(); i++){
        for (int j = 0; j < fo.size(); j++) {
            int val = 0;
            for (int k = 0; k < ba.size(); k++) {
                if (ba[k] == fo[j]) {
                    if (val + 1 > dp[k]) {
                        dp[k] = val + 1;
                    } else val = dp[k];
                } else val = max(dp[k], val);
            }
            for (int k = 0; k < ba.size(); k++) {
                if (k == ba.size() - 1) ans = min(ans, n - 2 * dp[k]);
                else if (k == ba.size() - 2) ans = min(ans, n - 2 * dp[k] - 1);
            }
        }
        std::fill(all(dp), 0);
        ba.pop_back();
        fo.push_back(S[i]);
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
