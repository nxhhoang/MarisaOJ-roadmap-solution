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

void solve() {
    int n;
    cin >> n;
    vector<vector<ll>> mtr(n, vector<ll>(n));

    FOR(i, 0, n) FOR(j, 0, n) cin >> mtr[i][j];

    FOR (i, 0, n) FOR(j, 0, n) {
        int val = mtr[i][j];
        mtr[i][j] = 0;
        if (i) mtr[i][j] = mtr[i - 1][j];
        if (j) mtr[i][j] = max(mtr[i][j], mtr[i][j - 1]);
        mtr[i][j] += val;
    } 

    cout << mtr[n - 1][n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
