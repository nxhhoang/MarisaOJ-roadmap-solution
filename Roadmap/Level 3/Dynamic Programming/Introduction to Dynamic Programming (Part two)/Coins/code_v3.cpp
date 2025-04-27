// nxhhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define endl '\n'
#define ub upper_bound // find X < min(x)
#define lb lower_bound // find X <= min(x)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 1000 + 3;
const int MAXSIZE = 1e5 + 5;
const int MAXN = 1e6 + 3;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int arr[1001];
int dp[MAXSIZE];

void solve(){
    int n, k;
    cin >>  n >> k;
    fill(dp, dp + k + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++)
        for (int j = arr[i]; j <= k; j++)
            if (dp[j - arr[i]] != INT_MAX) dp[j] = min(dp[j], dp[j - arr[i]] + 1);
    
    cout << (dp[k] != INT_MAX ? dp[k] : -1);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
