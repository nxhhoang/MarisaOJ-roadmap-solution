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

vector<vi> dp(100, vi(MAXSIZE, 0));
int n, S;
int maxV = 0;

void backtrack(int sum, int weight, int i, vector<pii> &vec) {
    if (weight <= S) {
        if (dp[i][weight] > sum) return;
        dp[i][weight] = sum;
        maxV = max(sum, maxV);
    }
    else return;
    if (i >= n) return;
    backtrack(sum + vec[i].second, weight + vec[i].first, i + 1, vec);
    backtrack(sum, weight, i + 1, vec);

}

void solve(){
    cin >> n >> S;
    vector<pii> vec(n);
    for(int i = 0; i < n ; i++){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(all(vec));
    backtrack(0, 0, 0, vec);
    cout << maxV << endl;
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
