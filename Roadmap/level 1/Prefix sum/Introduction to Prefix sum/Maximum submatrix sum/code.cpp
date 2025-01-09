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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    vector<vector<ll>> pre(n + 1, vector<ll> (m + 1));
    FOR(i, 0, n) {
        FOR(j, 0, m){
            cin >> a[i][j];
            pre[i + 1][j + 1] = a[i][j] + pre[i + 1][j] + pre[i][j + 1] - pre[i][j];
        }
    }

    ll maxx = LLONG_MIN; 
    FOR(i, 0, n) {
        FOR(j, i + 1, n + 1) {
            ll minV = 0;
            FOR(k, 1, m + 1) {
                minV = min(minV, pre[j][k] - pre[i][k]);
                maxx = max(maxx, pre[j][k] - pre[i][k] - minV);
                //cout << pre[j][k] <<"    "<< pre[i][k] <<" ---- " << pre[j][k] - pre[i][k] << endl;
                //cout <<"hang1:"<< i <<"  hang2:" << j << "  cot:"<<k << "   " << minV << "   " << maxx << endl;
            }
        }
    }

    cout << maxx << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
