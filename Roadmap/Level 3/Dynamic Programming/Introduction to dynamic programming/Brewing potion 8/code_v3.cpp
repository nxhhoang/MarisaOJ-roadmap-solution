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
    int n; 
    cin >> n;
    vector<vector<pii>> tre(n, vector<pii>(n, pii(INT_MAX, INT_MAX)));
    for (int i = 0; i < n; i++) {
        tre[0][i].first = 0; // luu min
        cin >> tre[0][i].second; // luu val
        int j = i - 1; // i = 5 j = 4 val = 1
        while (j >= 0) {
            int val = i - j;
            tre[val][j].second = (tre[val - 1][j].second + tre[0][i].second) % 100;
            for (int k = 0; k < val; k++) {
                int tich = tre[k][j].second * tre[val - k - 1][j + k + 1].second;
                tre[val][j].first = min(tre[val][j].first, 
                                        tre[k][j].first + tre[val - k - 1][j + k + 1].first + 
                                        tich); 
            }
            j--;
        }
    }
    cout << tre[n - 1][0].first << endl;
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
