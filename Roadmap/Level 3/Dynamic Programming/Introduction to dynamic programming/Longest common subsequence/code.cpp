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
    int n, a;
    cin >> n;
    vector<int> A(n);
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n; i++){
        cin >> a;
        int maxV = 0;
        for (int j = 0; j < n; j++) {
            if (a == A[j]) {
                int oldV = dp[j];
                dp[j] = max(maxV + 1, dp[j]);
                maxV = max(oldV, maxV);
            }
            else maxV = max(dp[j], maxV);
        }
    }
    int maxV = 0;
    for (int i = 0; i < n; i++) maxV = max(maxV, dp[i]);
    cout << maxV;
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
