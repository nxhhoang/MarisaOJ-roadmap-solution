// nxxhoang - the dreamer
#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define ub upper_bound  // find X < min(x)
#define lb lower_bound  // find X <= min(x)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MAXSIZE = 1e5 + 5;
const int MAXN = 2e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0}; 
const int dy[] = {0, 0, 1, -1};

void solve(){
    int n, l, r;
    cin >> n;
    vector<vi> vec(1e5 + 2, vi());
    vector<int> dp(1e5 + 2, 0);

    FOR(i, 0, n) {
        cin >> l >> r;
        vec[r].push_back(l);
    }

    for (int i = 1; i < 1e5 + 2; i++){
        dp[i] = dp[i - 1];
        for (int j = 0; j < vec[i - 1].size(); j++)
            dp[i] = max(dp[i], dp[vec[i - 1][j]] + (i - 1) - vec[i - 1][j] + 1);
    }
    cout << dp[MAXSIZE - 4];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
