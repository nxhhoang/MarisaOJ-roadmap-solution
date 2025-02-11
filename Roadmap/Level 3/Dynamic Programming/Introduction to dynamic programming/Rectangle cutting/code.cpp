// nxxhoang - the dreamer
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

int mat[501][501] = {0};

void solve() {
    int a, b;
    cin >> a >> b;
    FOR (i, 1, a + 1){
        FOR (j, 1, b + 1) {
            if (i == j) mat[i][j] = 0;
            else {
                mat[i][j] = MOD;
                FOR (k, 1, i) mat[i][j] = min(mat[i][j], mat[k][j] + mat[i - k][j] + 1);
                FOR (k, 1, j) mat[i][j] = min(mat[i][j], mat[i][k] + mat[i][j - k] + 1);
            }
        }
    }
    cout << mat[a][b];
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
