// nxhhoang - the dreamer
// g++ -std=c++11 -Wall -Wextra -O2 B.cpp -o B.exe
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
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

vector<ull> hass(2 * MAXN + 1, 1);
vector<ull> base(2 * MAXN + 1, 1);
ull vbase = 331;

ull getHash(int l, int r) {
    return hass[r] - hass[l] * base[r - l];
}

void solve()
{
    string s;
    cin >> s;

    int n = s.size();
    s += s.substr(0, n - 1);
    for (int i = 1; i <= 2 * n - 1; i++) {
        base[i] = (base[i - 1] * vbase);
        hass[i] = (hass[i - 1] * vbase + s[i - 1] - 'a' + 1);
    }

    int cur = 0;
    for (int i = 1; i < n; i++) {
        if (s[cur] != s[i]) {
            if (s[cur] > s[i]) cur = i;
            continue;
        } 
        int l = 0, r = n, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (getHash(i, i + mid) != getHash(cur, cur + mid)) r = mid;
            else l = mid + 1;
        }
        if (s[i + l - 1] < s[cur + l - 1]) cur = i;

    }
    cout << s.substr(cur, n);
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
