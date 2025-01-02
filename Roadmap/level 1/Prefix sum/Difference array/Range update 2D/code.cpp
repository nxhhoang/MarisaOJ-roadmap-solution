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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> mt(n + 2, vector<int>(m + 2, 0));

    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        mt[a][b]++;
        mt[a][d + 1]--;
        mt[c + 1][b]--;
        mt[c + 1][d + 1]++;
    }

    for(int j = 1; j < m + 1; j++){
        for(int i = 1; i < n + 1; i++){
            mt[i][j] += mt[i][j - 1];
        }
    }

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            mt[i][j] += mt[i - 1][j];
            cout << mt[i][j] << " "; 
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
