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
    vector<vector<ll>> tre(n, vector<ll>(n, ll(LLONG_MAX)));
    vector<ll> preF(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a; // luu val
        preF[i + 1] = preF[i] + a;
        tre[0][i] = 0; // luu min
        int j = i - 1; // i = 5 j = 4 val = 1
        int dem = 0;
        while (j >= 0) {
            int val = i - j;
            ll tong = preF[i + 1] - preF[j];
            for (int k = 0; k < val; k++) {
                tre[val][j] = min(tre[val][j], 
                                        tre[k][j] + tre[val - k - 1][j + k + 1] + 
                                        tong); 
            }
            j--;
        }
    } 
    cout << tre[n - 1][0] << endl;
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
