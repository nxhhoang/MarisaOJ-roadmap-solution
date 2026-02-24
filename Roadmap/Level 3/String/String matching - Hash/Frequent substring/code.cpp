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
const int MSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

vector<ull> hass(MSIZE, 0);
vector<ull> base(MSIZE, 1);
ull vbase = 331;
string s;
int k ;

ull query(int l, int r) {
    return hass[r] - hass[l] * base[r - l];
}

void solve()
{
    cin >> s >> k;

    for (int i = 1; i <= s.size(); i++) {
        base[i] = base[i - 1] * vbase;
        hass[i] = hass[i - 1] * vbase + s[i - 1];
    }
    
    int l = 0, r = s.size() + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        unordered_map<ull, int> mp;
        bool ok = true;
        for (int i = mid; i <= s.size(); i++)  {
            ull val = query(i - mid, i);
            mp[val]++;
            if (mp[val] >= k) {
                ok = false;
                break;
            }
        }
        if (ok) r = mid;
        else l = mid + 1;
    }
    cout << l - 1;
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
