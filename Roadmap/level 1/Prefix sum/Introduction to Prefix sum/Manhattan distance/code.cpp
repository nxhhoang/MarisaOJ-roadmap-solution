#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using namespace std;
using ll = long long;

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MOD = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> rotate_mt(2 * n - 1, vector<int>(2 * n - 1, 0));
    vector<vector<int>> p(2 * n, vector<int> (2 * n, 0));

    FOR(i, 0, n) FOR(j, 0, n) cin >> rotate_mt[i + j][n - 1 - i + j];
    FOR(i, 1, 2 * n) FOR(j, 1, 2 * n) p[i][j] = rotate_mt[i - 1][j - 1] + p[i][j - 1] + p[i - 1][j] - p[i - 1][j - 1];

    FOR(i, 0, n) {
        FOR(j, 0, n){
            int aa = min(2 * n - 1, i + j + 1 + k);
            int bb = min(2 * n - 1, n - i + j + k);
            int cc = max(0, i + j - k);
            int dd = max(0, n - 1 - i + j - k);
            cout << p[aa][bb] - p[aa][dd] - p[cc][bb] + p[cc][dd] << " ";
        }
        cout << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
