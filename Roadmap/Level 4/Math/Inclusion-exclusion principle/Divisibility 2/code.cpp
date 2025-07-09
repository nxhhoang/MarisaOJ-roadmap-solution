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

    ll n, L , R;
int pri[21];
vector<pair<ll, int>> mes;
void backtrack(int cnt, ll dov, int i) {
    if (i >= n) {
        mes.push_back({dov, cnt});
        return;
    }

    backtrack(cnt, dov, i + 1);
    if (R / pri[i] >= dov) backtrack(cnt + 1, dov * pri[i], i + 1);
}

void solve()
{
    cin >> n >> L >> R;
    for (int i = 0; i < n; i++)      cin >> pri[i];
    sort(pri, pri + n, greater<int>());
    int cnt = 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (pri[i] == pri[j]) cnt++;
        else pri[++j] = pri[i];
    }
    L--;
    n -= cnt;
    backtrack(0, 1, 0);
    ll sum = 0;
    for (int i = 1; i < mes.size(); i++){
        if (mes[i].second % 2) sum += mes[i].second * (R / mes[i].first - L / mes[i].first); 
        else sum -= mes[i].second * (R / mes[i].first - L / mes[i].first);
    }
    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t; // DLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
    while (t--)
    {
        solve();
    }
    return 0;
}
